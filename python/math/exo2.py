u = 280
n = 0
y = u
while u < 380:
    n = n+1
    u = 0.9 * u + 42
    y += u
    
print( "nombre de vehicule = ", u, "rang = ", n)

while n < 12:
    n = n+1
    u = 0.9 * u + 42
    y += u
    
print ("nombre de vehicule en une année = ", y)