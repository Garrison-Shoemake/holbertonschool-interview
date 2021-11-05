#!/usr/bin/python3
""" This is a lockbox interview question and determines if all boxes can be opened"""


def canUnlockAll(boxes):
	keyring = [0]
	if boxes is None or len(boxes) == 0:
		return False

	for key in keyring:
		newkeys = boxes[key]
		keyring = addkey(keyring, newkeys)

	return len(keyring) == len(boxes)

def addkey(keyring, newkeys):
	for key in newkeys:
		if key not in keyring:
			keyring.append(key)
			keyring.sort()
		else:
			pass
	return keyring
