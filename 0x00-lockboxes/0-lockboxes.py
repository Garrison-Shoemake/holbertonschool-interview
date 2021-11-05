#!/usr/bin/python3
""" This is a lockbox interview question and determines if all boxes can be opened"""


def canUnlockAll(boxes):
	""" Determines if all boxes can be unlocked or not """
	keyring = [0]
	if boxes is None or len(boxes) == 0:
		return False

	for keys in keyring:
		for key in boxes[keys]:
			if key not in keyring and key < len(boxes):
				keyring.append(key)
		
	return len(keyring) == len(boxes)

# def addkey(keyring, newkeys):
# 	for key in newkeys:
# 		if key not in keyring:
# 			keyring.append(key)
# 			keyring.sort()
# 		else:
# 			pass
# 	return keyring
