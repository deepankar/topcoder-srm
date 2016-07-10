import sys
import bisect
def get_factors(n):
    'returns all factors as a list'
    l = reduce(list.__add__, 
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))
    l.sort()
    return l

def find_gt(a, x):
    'binary search: Find leftmost value greater than x'
    i = bisect.bisect_right(a, x)
    if i != len(a):
        return a[i]
    raise ValueError

class Procrastination:
  factors = {}
  def smallestfac_gt(self, n, gt):
    if n in self.factors:
      f = self.factors[n]
    else:
      f = get_factors(n)
      self.factors[n] = f

    res =  find_gt(f, gt)
    return res

  def findFinalAssignee(self, n):
    if (n <= 3):
      return n
    if n == 4:
      return 5
    sf = 1
    while True:
      sf_n = self.smallestfac_gt(n, sf)
      sf_n_min_1 = self.smallestfac_gt(n-1, sf)
      if sf_n < sf_n_min_1:
#        print "F" + str(n) + " " + str(sf_n) + " " + str(sf_n_min_1)
        if sf_n == n:
          return n
        n = n+1
        sf = sf_n
      else:
#        print "B" + str(n) + " " + str(sf_n) + " " + str(sf_n_min_1)
        if sf_n_min_1 == n-1:
          return n
        n = n-1
        sf = sf_n_min_1
    return n

t = Procrastination()
#print t.findFinalAssignee(int(sys.argv[1]))
assert t.findFinalAssignee(2) == 2
assert t.findFinalAssignee(3) == 3
assert t.findFinalAssignee(4) == 5
assert t.findFinalAssignee(5) == 4
assert t.findFinalAssignee(8) == 11
assert t.findFinalAssignee(20) == 20
assert t.findFinalAssignee(196248) == 196259
assert t.findFinalAssignee(5587021440) == 5587021440

#prime factorization
def primes(n):
    primfac = []
    d = 2
    while d*d <= n:
        while (n % d) == 0:
            primfac.append(d)  # supposing you want multiple factors repeated
            n //= d
        d += 1
    if n > 1:
       primfac.append(n)
    return primfac

#  def smallestfac_gt_mid(self, n, gt):
#    if n in self.sknown and self.sknown[n] > gt:
#      return self.sknown[n]
#    minfac = gt+1
#    sq = n**0.5
#    if minfac == sq:
##    print "sq of %d is %f " % (n, sq)
#      return int(sq)
#    if minfac < sq:
#      d = gt + 1
#      while d*d <= n:
#        if (n % d) == 0:
#          self.sknown[n] = d
#          return d
#        d += 1
#    d = n/minfac
#    while d > 1:
#      if (n % d) == 0:
#        self.sknown[n] = n/d
#        return n/d
#      d -= 1
#    self.sknown[n] = n
#    return n
#  
