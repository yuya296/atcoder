import math
a, b, d = map(int, input().split())

theta = math.radians(d)

a2 = a * math.cos(theta) - b * math.sin(theta)
b2 = a * math.sin(theta) + b * math.cos(theta)

print(a2, b2)