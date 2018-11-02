from optparse import OptionParser
import csv

def option_parser():
    parser = OptionParser()
    parser.add_option("-c", "--config", dest="config",
                  help="path to config file")
    parser.add_option("-d", "--data", dest="datafile",
                  help="path to data file")
    return parser

class Record:
    def __init__(self, row):
        self.data = {}
        for src_name, dst_name in field_names:
            self.data[dst_name] = row[src_name]

    def __repr__(self):
        return '{' + ', '.join([key + ": '" + value + "'" for key, value in self.data.iteritems()]) + '}'

    def valid(self):
        for name in required_names:
            if (name not in self.data) or (self.data[name] is None) or (len(self.data[name]) == 0):
                return False
        return True

field_names = []
required_names = ['employer_name', 'job_title', 'wage_rate_lo', 'wage_rate_unit', 'work_loc_city']

def main():
    global field_names
    print 'salary-data-converter'
    parser = option_parser()
    (options, args) = parser.parse_args()
    field_names = [tuple(item.strip() for item in line.split()) for line in open(options.config) if len(line.strip())]
    for field in field_names:
        print field
    count = 0
    invalid = 0
    for row in csv.DictReader(open(options.datafile, 'rU'), dialect=csv.excel):
        rec = Record(row)
        if not rec.valid():
            print 'Invalid Record'
            invalid += 1
            continue
        # print rec
        count += 1
    print 'count = %s, invalid = %s' % (count, invalid)


if __name__ == '__main__':
    main()