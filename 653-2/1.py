class CountryGroup:
  def solve(self, a):
    cur_c = -1
    cur_c_start = -1
    next_change_i = 0
    numc = 0
    for i in xrange(len(a)):
      if i == next_change_i:
        cur_c = a[i]
        cur_c_start = i
        next_change_i = i+a[i]
        numc = numc+1
      elif a[i] != cur_c:
          return -1

    if next_change_i != len(a):
      return -1

    return numc


cg = CountryGroup()
print cg.solve((2,2,3,3,3))
print cg.solve((1,1,1,1,1))
print cg.solve((3,3))
print cg.solve((4,4,4,4,1,1,2,2,3,3,3))
print cg.solve((2,1,2,2,1,2))
