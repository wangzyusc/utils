from optparse import OptionParser
import csv

def option_parser():
    parser = OptionParser()
    parser.add_option("-c", "--config", dest="config",
                  help="path to config file")
    parser.add_option("-d", "--data", dest="datafile",
                  help="path to data file")
    return parser

if __name__ == '__main__':
    print 'salary-data-converter'
    parser = option_parser()
    (options, args) = parser.parse_args()
    field_names = [tuple(item.strip() for item in line.split()) for line in open(options.config) if len(line.strip())]
    for field in field_names:
        print field
    count = 0
    for row in csv.DictReader(open(options.datafile), dialect=csv.excel):
        for name in field_names:
            if name in row:
                print name + ': ' + row[name]
        count += 1
        if count > 5:
            break
