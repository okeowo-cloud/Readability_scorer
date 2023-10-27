#!/usr/bin/python3
from load_c.load import load
import unittest

source_files = [
  'src/auto_readability.c',
  'src/word_attributes.c'
  ]

module, ffi = load(source_files, './include', module_name="auto_readability_")

class ColemanLiauTest(unittest.TestCase):

  def testColemanLiauScore(self):
    s = "Nam pretium est ut sollicitudin lobortis. Vestibulum sed gravida odio. Mauris quis purus magna. Donec pellentesque dictum eleifend. Phasellus tempus enim non nulla sollicitudin, nec accumsan nulla lobortis.".encode('utf-8')

    self.assertEqual(round(module.getARScore(s), 2), 11.48)

if __name__ == '__main__':
  unittest.main()
