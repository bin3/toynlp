#!/usr/bin/env python

import sys
import argparse
from collections import defaultdict
from collections import Counter

def run(args):
  dic = set()
  wcnt = 0
  for i, indict in enumerate(args.dicts):
    print('Processing dict# %d: %s' % (i, indict))
    with open(indict) as df:
      for line in df:
        dic.add(line.strip())
        wcnt += 1

  print('Read %d words and %d different words' % (wcnt, len(dic)))
  with open(args.dictf, 'w') as df:
    for word in dic:
      df.write(word + '\n')

if __name__ == '__main__':
  print('------%s------' % sys.argv[0])
  parser = argparse.ArgumentParser(description='Merge multiple dictionaries to one dictionary with unique words')
  parser.add_argument('dicts', nargs='+', help='the input dictionaries')
  parser.add_argument('-d', '--dictf', default='dict.txt', help='the output dictionary file')

  args = parser.parse_args()
  print('args: %s' % args)
  run(args)
