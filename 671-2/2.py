import bisect
class BearDartsDiv2:
  no_c = {}
  nw2_c = {}
  nw3_c = {}
  t = ()
  def no(self, x, n):
    if n <= 0:
      return 0
    cac = self.no_c.get((x,n))
    if cac is not None:
      return cac
    ans = self.no(x, n-1)
    if self.t[n-1] == x:
      ans+=1
    self.no_c[(x,n)] = ans
    return ans

  def nw2(self, p, n):
    if n <= 1:
      return 0
    cac = self.nw2_c.get((p,n))
    if cac is not None:
      return cac
    ans=self.nw2(p,n-1)
    if p % self.t[n-1] == 0:
      factor=p/self.t[n-1]
      ans += self.no(factor, n-1)
    self.nw2_c[(p,n)] = ans
    return ans

  def nw3(self, p, n):
    if n <= 2:
      return 0
    cac =  self.nw3_c.get((p,n))
    if cac is not None:
      return cac
    ans = self.nw3(p, n-1)
    if p % self.t[n-1] == 0:
      factor=p/self.t[n-1]
      ans += self.nw2(factor, n-1)
    self.nw3_c[(p,n)] = ans
    return ans

  def count(self, t):
    self.t = t
    self.no_c = {}
    self.nw2_c = {}
    self.nw3_c = {}
    n = len(t)
    ways = 0
    for i in xrange(3,n):
      ways += self.nw3(t[i], i)
    return ways

  def countslow(self, t):
    n = len(t)
    ways = 0
    d = {}
    for i in xrange(0,n):
      v = t[i]
      if d.has_key(v):
        d[v] = d[v] + (i,)
      else:
        d[v] = (i,)

    for i in xrange(0,n-3):
      for j in xrange(i+1,n-2):
        for k in xrange(j+1,n-1):
          p = t[i]*t[j]*t[k]
          locs = d.setdefault(p, ())
          firstpos=bisect.bisect(locs,k)
          ways += (len(locs)-firstpos)

    return ways


cg = BearDartsDiv2()
print cg.count((1, 8, 1, 8, 32, 128, 1, 1, 131072, 1, 2, 4096, 1, 1, 8, 8, 262144, 32, 4, 1, 4, 1, 262144, 1, 1, 4, 8, 1, 1, 1, 1, 256, 2, 32, 4, 2048, 256, 2, 2, 4, 1, 1, 32, 1, 1, 16384, 4, 1, 4, 16, 4, 2, 2, 8, 4, 8, 2, 4, 1, 4, 2, 512, 2, 16, 4, 128, 16, 32, 16, 32, 8, 128, 8, 2, 2, 128, 1, 16, 8, 8, 2048, 2, 4, 2, 2, 8, 8, 1, 2, 1, 8, 64, 128, 1, 4, 1, 16, 64, 2, 32, 8, 4, 4, 256, 16, 32, 2, 4, 4, 1, 2, 8, 1, 1, 1, 8, 32, 1, 1, 1, 2, 2, 1, 4, 2, 1, 1, 4, 4, 4096, 1, 4, 256, 8, 2, 16, 2, 128, 8, 128, 1, 32, 1, 4, 1, 1, 64, 1, 2, 32, 2048, 2048, 32, 64, 16, 4, 1, 1, 8, 2, 16, 1, 1, 16, 1, 2, 2, 2, 32, 1, 4, 8, 2, 512, 1, 2048, 1, 8, 1, 2, 64, 2, 64, 262144, 4, 2, 1, 16, 8, 1, 1, 8, 8, 2, 8, 2, 1, 2, 8, 8, 4, 2, 4, 16, 32, 16, 8, 1, 2, 2, 1, 2, 4, 8, 2, 256, 1024, 8, 256, 8, 128, 1, 2, 4, 2, 8, 2, 8, 4, 8, 1, 1, 8192, 4, 2, 64, 4, 16, 2, 8, 64, 8, 8, 32, 64, 8, 1, 1, 8, 16, 4, 2048, 2, 32, 4, 1, 16, 64, 1, 8, 2, 8, 16, 1, 1, 1, 64, 1, 2048, 1, 2, 2, 1, 2, 1, 2, 2, 4096, 2, 2, 1, 32768, 8, 2, 2, 2, 8, 8, 16, 2, 2, 256, 2, 4, 1, 4, 64, 4096, 1, 8, 4, 64, 2, 1, 16384, 1, 1, 1, 8, 64, 65536, 4, 2, 64, 32, 16, 8, 32, 4, 8, 2, 16, 32, 2, 1, 8, 4, 32, 4, 2, 16, 4, 64, 8, 32, 512, 131072, 4, 2, 16, 2, 1, 1, 8, 512, 16, 4, 2048, 4096, 1, 2, 4, 16, 1, 8, 64, 8192, 1, 1, 4, 2, 4, 2, 2, 4, 1024, 2, 1, 2, 2, 256, 16, 16, 1, 1, 4, 32, 32, 1, 1, 2, 256, 4, 1, 2, 8, 32, 4, 2, 1, 32, 2, 1, 1, 2, 1, 1, 64, 1, 1, 2, 2, 1, 1, 1, 1, 4, 4, 1, 4, 4, 4096, 2, 1, 2, 4, 131072, 1, 2, 64, 2, 1, 128, 64, 4, 4, 2, 1, 128, 32, 8, 2, 32, 1, 4, 4, 128, 32, 2, 64, 4096, 1, 2, 8, 512, 32, 1, 4096, 32, 2, 2, 2, 256, 256, 32, 2, 2, 1, 2, 8, 1, 1, 4, 1, 16, 1, 1, 2, 2, 2, 4, 4, 1, 8, 4, 4, 1024, 8, 8, 64, 1, 262144, 4, 1, 4096, 1, 2, 2, 8, 1, 256, 2, 8, 2048, 1, 2, 8, 1, 16384, 1))
print cg.count((50, 1, 100000, 2, 1, 1, 1, 2, 1, 100000, 50, 1, 1, 1, 1, 1000, 10000, 1, 1000, 10, 1000000, 1, 1, 10000, 5000, 100, 10, 1, 2, 1, 1, 1, 10000, 10, 1, 1, 1, 1, 1, 100, 1000000, 1, 1, 1, 1, 1, 50, 100000, 1, 1, 1, 1, 10, 1, 1, 1, 2, 1, 1, 5, 1000000, 2, 10000, 1, 1, 50000, 1000, 1, 1000000, 100000, 1, 100, 5, 1, 1000000, 1, 100000, 1, 1, 1, 1, 1, 10000, 1, 1, 50000, 1, 1, 100, 10000, 1, 1, 1, 1, 1, 10000, 2, 1, 1, 2, 1, 5, 2, 1, 1, 500000, 1, 10, 5, 1, 1, 1, 1, 1, 10000, 2, 5, 50000, 1, 100, 1, 10, 1, 1, 2, 5000, 100, 1000000, 100, 50, 1, 1, 1, 1, 5, 500, 5000, 100, 2, 1, 1, 5, 100000, 1000000, 2, 1, 1, 1, 2, 2, 100000, 10, 2, 5, 100000, 1, 10000, 1, 500, 1, 1, 2, 1, 1, 10, 1, 1000000, 1, 1, 1, 1, 10, 1, 779625, 1, 1000000, 1, 2, 1000000, 10, 1, 1, 10, 1, 10, 1, 10, 1000, 1, 1, 500, 1, 100000, 2, 500000, 2, 1, 500000, 10, 2, 1, 5, 2, 1, 1, 1, 5, 50000, 1, 10, 5, 50, 10, 2, 2, 2, 1, 1000, 1, 10000, 1000000, 5, 2, 1, 50, 1000000, 10000, 50000, 1, 1, 1, 10, 1, 1000, 1, 5, 1, 1000000, 5, 1, 1, 1, 1000000, 1, 1, 1, 5, 5000, 1, 5, 1000, 1, 1, 1, 2, 1, 1, 2, 1, 1, 10, 1, 1, 2, 500, 500000, 1, 1, 100, 1000000, 2, 1, 1, 1, 1, 2, 50, 1, 1, 1, 10, 2, 2, 1, 1, 1, 2, 1, 1000000, 10000, 2, 100000, 1, 1, 1, 2, 2, 10, 1, 2, 1, 1, 1, 10, 1, 2, 1, 50000, 1, 1, 1, 10, 1, 1000000, 1, 1, 1, 10, 10, 17492, 100000, 1000, 1000000, 10, 1000, 1, 1000000, 1, 1, 10, 5, 1, 100, 1, 1, 50, 2, 5, 1, 1, 5, 5000, 1, 1, 100, 1, 5, 2, 1, 10, 1, 50, 50, 1, 1, 739145, 1, 1000000, 10, 1, 1, 1, 100, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 100000, 10, 1, 1, 100, 5000, 1, 50, 1, 1, 10, 1, 1, 1, 1, 1000000, 1, 1, 1000000, 1, 1, 100000, 1, 1, 1, 10000, 5, 2, 1, 100, 1, 10, 2, 10, 1000, 100, 1, 2, 5000, 5, 1, 1, 100, 1, 1, 500, 2, 500, 1, 100000, 1, 1, 1, 10, 1, 1, 117948, 1, 1000, 1, 2, 1, 1, 1000000, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 10, 1, 1, 2, 10, 500, 10, 2, 2, 100000, 1, 10, 2, 2, 100000, 10, 2, 500000, 1, 5, 2, 1000000, 100, 10, 1, 2, 5, 1, 1000000, 1, 1, 1, 10, 1000000, 2, 1, 2, 2, 5000, 1, 1, 2, 1, 1000000, 1, 1, 2, 1000000, 1000000, 1, 10, 1000, 1))
print "#########",cg.count((10,2,2,7,40,160))
print "#########",cg.count((128,64,32,16,8,4,2,1))
print "#########",cg.count((2,3,4,5,6,8,12,16,20,24,40,24,20,16,12,8,6,5,4,3,2))
print "#########",cg.count((100,100,100,1000000,1000000,1000000,1000000,1000000))
print "#########",cg.count((1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1))
