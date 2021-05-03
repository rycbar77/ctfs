︠9e0c12f2-9fce-4255-a3c1-c17571d05a01︠
#define the elliptic curve corresponding to the equation a/(b+c)+b/(a+c)+c/(a+b)=4
ee=EllipticCurve([0,109,0,224,0])
︡2d123642-50d2-4db3-b6da-be0533f8ea1e︡{"done":true}︡
︠669911fc-be57-4b7c-9615-04f8a0b6741bs︠
ee
︡e956a190-112d-4eee-9955-7519b0d79027︡{"stdout":"Elliptic Curve defined by y^2 = x^3 + 109*x^2 + 224*x over Rational Field\n"}︡{"done":true}︡
︠df0266d7-6190-4788-8e9e-9de3a7a5d67fs︠
ee.rank()
︡94b88961-b0b0-4ad0-b388-7888c2e45de3︡{"stdout":"1"}︡{"stdout":"\n"}︡{"done":true}︡
︠4bda648e-cccd-4e8a-9658-fc95b698a2d3s︠
ee.gens()
︡429ea0a1-9db1-47d5-8826-15c6fc96e215︡{"stdout":"[(-100 : 260 : 1)]"}︡{"stdout":"\n"}︡{"done":true}︡
︠9d5d4449-ad29-492c-aa02-cf3c56cc815a︠
P=ee(-100,260) # this is a generator for the group of rational points
︡2303815e-848f-4e6f-9473-134ddd5ad26e︡{"done":true}︡
︠32631ca4-467e-4e73-a4e2-1a9402d99ca3︠

2*P # just a check
︡bbe0b991-21f5-4ab2-b15c-ab1913dea17b︡{"stdout":"(8836/25 : -950716/125 : 1)\n"}︡{"done":true}︡
︠866fe1bf-0cd2-4a43-9de7-f7d18ee68925︠
# Convert a point (x,y) on the elliptic curve back to (a,b,c). This has N as an argument, but in our case N=4.
# We also ensure that the result is all integers, by multiplying by a suitable lcm.
def orig(P,N):
    x=P[0]
    y=P[1]
    a=(8*(N+3)-x+y)/(2*(N+3)*(4-x))
    b=(8*(N+3)-x-y)/(2*(N+3)*(4-x))
    c=(-4*(N+3)-(N+2)*x)/((N+3)*(4-x))
    da=denominator(a)
    db=denominator(b)
    dc=denominator(c)
    l=lcm(da,lcm(db,dc))
    return [a*l,b*l,c*l]

︡0b380f3d-f821-42c9-8c37-4bf3281a8454︡{"done":true}︡
︠ae130e49-4cde-4c82-a6f4-d174976e7ec2s︠
orig(P,4)
︡a9f8f9c2-1c9c-4d91-8e3c-964714b1f788︡{"stdout":"[4, -1, 11]\n"}︡{"done":true}︡
︠f6690b55-e3ac-4de6-98c6-d8c8c659f938︠
u=orig(9*P,4) # Bremner and MacLeod noticed that 9P yields a positive solution. 
︡a3c620c9-6bc3-400a-89c3-f1d2bd0a081c︡{"done":true}︡
︠5510cc0b-40d2-460f-b05f-522fc89d961cs︠
(a,b,c)=(u[0],u[1],u[2])
(a,b,c)
︡05ed4495-c278-4563-ba2d-5a0d788558f4︡{"stdout":"(154476802108746166441951315019919837485664325669565431700026634898253202035277999, 36875131794129999827197811565225474825492979968971970996283137471637224634055579, 4373612677928697257861252602371390152816537558161613618621437993378423467772036)\n"}︡{"done":true}︡
︠cefa7ef6-4947-4d60-b91b-d80cb01c2b4bs︠
a/(b+c)+b/(a+c)+c/(a+b)
︡4f19b0a5-c4f3-4dea-ad41-fa7653c67ee8︡{"stdout":"4\n"}︡{"done":true}︡
︠0bc523ce-72ea-4b51-9d3f-7704204d54a7︠

# It works!









