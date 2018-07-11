import argparse
import sys

# parse=argparse.ArgumentParser()
# parse.add_argument("--learning_rate",type=float,default=0.01,help="initial learining rate")
# parse.add_argument("--max_steps",type=int,default=2000,help="max")
# parse.add_argument("--hidden1",type=int,default=100,help="hidden1")
# flags,unparsed=parse.parse_known_args(sys.argv[1:])

import numpy as np
def bucket_sort(array):
	n = len(array)
	bucket = list()
	# build bucket
	for i in xrange(n):
		bucket.append(list())
	# print(bucket)
	for j, data in enumerate(array):
		bucket[int(n * data)].append(data)
	# sort data in each bucket
	for i in xrange(n):
		bucket[i] = np.sort(bucket[i])
	# combine result in each bucket
	result = np.array([])
   	for i in xrange(n):
   		result = np.hstack((result, bucket[i]))
   	return result


if __name__ == "__main__":
	array = np.array([0.23,0.12,0,0.24,0.98,0.65])
	print(array)
	result = bucket_sort(array)
	print(result)