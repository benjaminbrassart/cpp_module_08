#!/usr/bin/env python3

import random
import sys

if len(sys.argv) != 2:
	print("Expected 1 argument, %d given" % (len(sys.argv) - 1))
	exit(1)

values = random.sample(range(0, 200), int(sys.argv[1]))
print("\n".join([str(v) for v in values]))
