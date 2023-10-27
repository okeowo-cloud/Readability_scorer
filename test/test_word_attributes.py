#!/usr/bin/python3
from load_c.load import load
import unittest
import re

source_files = [
  'src/word_attributes.c'
  ]

module, ffi = load(source_files, './include', module_name="word_attributes_")

class WordAttributesTest(unittest.TestCase):

  def testSimpleText(self):
    s = "Nam pretium est ut sollicitudin lobortis. Vestibulum sed gravida odio. Mauris quis purus magna."
    s_bytes = s.encode('utf-8')
    self.assertEqual(module.getNoOfCharacter(s_bytes), len(s.replace(" ", "")))
    self.assertEqual(module.getNoOfSentence(s_bytes), len(re.split('[.?!]', s))-1)
    self.assertEqual(module.getNoOfWords(s_bytes), len(s.split()))


  def testModerateText(self):
      s1 = "Do you like Cheese Whiz? Spray tan? Fake eyelashes? That's what is Lorem Ipsum to many? It rubs them the wrong way, all the way. It's unreal, uncanny, makes you wonder if something is wrong, it seems to seek your attention for all the wrong reasons! Usually, we prefer the real thing, wine without sulfur based preservatives, real butter, not margarine, and so we'd like our layouts and designs to be filled with real words, with thoughts that count, information that has value."
      s1_bytes = s1.encode('utf-8')
      self.assertEqual(module.getNoOfCharacter(s1_bytes), len(s1.replace(" ", "")))
      self.assertEqual(module.getNoOfSentence(s1_bytes), len(re.split("[.?!]", s1))-1)
      self.assertEqual(module.getNoOfWords(s1_bytes), len(re.split(r'\s+', s1)))

  def testEmptyText(self):
      s2 = ""
      s2_bytes = s2.encode('utf-8')
      self.assertEqual(module.getNoOfCharacter(s2_bytes), 0)
      self.assertEqual(module.getNoOfSentence(s2_bytes), 0)
      self.assertEqual(module.getNoOfWords(s2_bytes), 0)


  def testFunnyTest(self):
      s3 = ":=====> <=======:"
      s3_bytes = s3.encode('utf-8')
      self.assertEqual(module.getNoOfCharacter(s3_bytes), len(s3.replace(" ", "")))
      self.assertEqual(module.getNoOfSentence(s3_bytes), 0)
      self.assertEqual(module.getNoOfWords(s3_bytes), 0)


if __name__ == '__main__':
  unittest.main()
