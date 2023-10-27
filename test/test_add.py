#!/usr/bin/python3
from load_c.load import load
import unittest

module, ffi = load('src/add.c', './include', module_name="add_")

class AddTest(unittest.TestCase):

  def testAddtion(self):
    self.assertEqual(module.add(1, 2), 1 + 2)

if __name__ == '__main__':
  unittest.main()
