#!/usr/bin/env python3

import random
import sys

pname = sys.argv[0]
argv = sys.argv[1:]
argc = len(argv)

if 0 < argc < 3:
    n = int(argv[0])
    if argc == 2:
        o = int(argv[1])
    else:
        o = n
    if o < n:
        print("Error: <max> cannot be less that <range>")
        exit(1)
    values = random.sample(range(0, o), n)
    print("\n".join([str(v) for v in values]))
    exit(0)

print("Usage: %s <range> <max>" % (pname))
exit(1)

