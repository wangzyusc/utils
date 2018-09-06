import os
import sys
from datetime import datetime

def usage():
    print 'python file_fetcher.py path_to_file/*.fileformat'


def main():
    if len(sys.argv) < 2:
        usage()
        return
    path = sys.argv[1].split('/')
    file_name, ext = path[-1].split('.')
    path = '/'.join(path[:-1])
    print 'path: ' + path
    result = []
    for root, dirs, files in os.walk(path):
        for file in files:
            if file.endswith("." + ext):
                 abs_path = os.path.join(root, file)
                 result.append((abs_path.decode('utf-8'), datetime.fromtimestamp(os.path.getmtime(abs_path))))
    result = sorted(result, key=lambda x: x[1])
    for record in result:
        print '%s: %s' % record


if __name__ == '__main__':
    main()
