"""
This script is to craw the continuous contents on sequential urls.
"""

import sys
reload(sys)
sys.setdefaultencoding("utf-8")

import os
from urllib import urlopen
from HTMLParser import HTMLParser

class HTMLParserStacker(HTMLParser):
    def __init__(self, res_list,
        ignore = ['img', 'input', 'table', 'style', 'link'],
        skip = ['dl', 'dd', 'tr', 'script']):
        HTMLParser.__init__(self)
        self._res_list = res_list
        self._in_content = False
        self._skip = False
        self._stack = []
        self._ignore_list = ignore
        self._skip_list = skip

    def handle_starttag(self, tag, attrs):
        if tag in self._ignore_list:
            return
        if tag in self._skip_list:
            self._skip = True
        for attr in attrs:
            if attr[0] == 'class' and attr[1] == 'content-body':
                # self._res_list.append(self.get_starttag_text())
                self._in_content = True
                print 'enter content: ' + str(self._stack)
                break
        if self._in_content and tag not in ['br']:
            self._stack.append(tag)

    def handle_endtag(self, tag):
        if self._skip and (tag in self._skip_list):
            self._skip = False
        elif self._in_content and tag == self._stack[-1]:
            self._res_list.append('</%s>' % tag)
            self._stack.pop()
            if len(self._stack) == 0:
                self._in_content = False

    def handle_startendtag(self, tag, attrs):
        if (not self._skip) and self._in_content:
            self._res_list.append(self.get_starttag_text())

    def handle_data(self, data):
        if (not self._skip) and self._in_content:
            self._res_list.append(data)

    def all_content(self):
        return self._res_list

    def clear_check(self):
        clear = True
        if self._in_content:
            clear = False
            self._in_content = True
        if len(self._stack) != 0:
            clear = False
            print 'stack: ' + str(self._stack)
            del self._stack[:]
        return clear

def validate(url):
    try:
        urlopen(url)
        return True, url
    except Exception as e:
        print "Error: '%s' is not valid url" % url
        print e

def fetch(url):
    content = []
    parser = HTMLParserStacker(content)
    for index in xrange(13):
        try:
            cur_url = url + '/' + str(index)
            print 'Fetch: %s' % cur_url
            f = urlopen(cur_url)
            r = f.read()
            parser.feed(r)
        except Exception as e:
            print "Error in fetch('%s'):\n%s" % (cur_url, e)
        if not parser.clear_check():
            print 'Warning: parser finished unclear!'
    return parser.all_content()

def merge_to_html(content_list, path):
    with open("./" + path, "w") as f:
        f.write('<html><head><title>Merge result</title></head><body>')
        for item in content_list:
            f.write(item)
        f.write('</body></html>')

def usage():
    print 'Usage: ' + os.path.basename(__file__) + ' url [result_path]'

if __name__ == '__main__':
    if len(sys.argv) < 2:
        usage()
        exit(0)
    url = sys.argv[1]
    res_path = sys.argv[2] if len(sys.argv) > 2 else './result.html'
    if not validate(url):
        exit(0)
    merge_to_html(fetch(url), res_path)
    print 'Finish'
