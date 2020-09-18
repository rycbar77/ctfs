直接Bytecode Viewer打开看一下MainActicity

```java
class MainActivity$1 implements OnClickListener {
   // $FF: synthetic field
   final MainActivity this$0;

   MainActivity$1(MainActivity var1) {
      this.this$0 = var1;
   }

   public void onClick(View var1) {
      String var4 = a.a(a.c(this.this$0.txt.getText().toString()));
      if (var4 != null && var4.length() > 0) {
         String var2 = this.this$0.a(var4);
         if (var2.length() > 0) {
            MainActivity var3 = this.this$0;
            StringBuilder var5 = new StringBuilder();
            var5.append("flag{");
            var5.append(var2);
            var5.append("}");
            Toast.makeText(var3, var5.toString(), 0).show();
         }
      }

   }
}
```

输入的字符串调用a类里面的c函数和a函数进行处理之后再调用native-lib里面的a函数生成输出的flag，根据判断条件猜测输入不正确会返回空字符串，先看class a，输入先经过c的处理

```java
public static byte[] c(String var0) {
      char[] var1 = var0.toCharArray();
      byte[] var5 = new byte[var0.length() / 2];

      for(int var2 = 0; var2 < var5.length; ++var2) {
         int var3 = "0123456789ABCDEF".indexOf(var1[var2 * 2]) * 16;
         if (var3 == -1) {
            return null;
         }

         int var4 = "0123456789ABCDEF".indexOf(var1[var2 * 2 + 1]);
         if (var4 == -1) {
            return null;
         }

         var5[var2] = (byte)((byte)(var3 + var4 & 255));
      }

      return var5;
   }
```

这里很明显是一个hex2byte的操作，然后传入a函数

```java
public static String a(byte[] var0) {
      if (var0 != null && var0.length != 0) {
         int var1 = var0.length * 8;
         int var2 = var1 % 24;
         int var3 = var1 / 24;
         if (var2 != 0) {
            var1 = var3 + 1;
         } else {
            var1 = var3;
         }

         char[] var4 = new char[var1 * 4];
         int var5 = 0;
         var1 = 0;

         int var6;
         char[] var11;
         for(var6 = 0; var6 < var3; ++var5) {
            int var7 = var5 + 1;
            byte var8 = var0[var5];
            var5 = var7 + 1;
            byte var9 = var0[var7];
            byte var16 = var0[var5];
            int var10 = var1 + 1;
            var11 = b;
            var4[var1] = (char)var11[(var8 & 252) >> 2];
            var1 = var10 + 1;
            var4[var10] = (char)var11[((var8 & 3) << 4) + ((var9 & 240) >> 4)];
            int var17 = var1 + 1;
            var4[var1] = (char)var11[((var9 & 15) << 2) + ((var16 & 192) >> 6)];
            var1 = var17 + 1;
            var4[var17] = (char)var11[var16 & 63];
            ++var6;
         }

         var3 = var5;
         var6 = var1;
         if (var2 == 8) {
            byte var13 = var0[var5];
            var6 = var1 + 1;
            var11 = b;
            var4[var1] = (char)var11[(var13 & 252) >> 2];
            var1 = var6 + 1;
            var4[var6] = (char)var11[(var13 & 3) << 4];
            var3 = var1 + 1;
            var4[var1] = (char)32;
            var6 = var3 + 1;
            var4[var3] = (char)32;
            var3 = var5 + 1;
         }

         if (var2 == 16) {
            var5 = var3 + 1;
            byte var14 = var0[var3];
            byte var15 = var0[var5];
            var3 = var6 + 1;
            char[] var12 = b;
            var4[var6] = (char)var12[(var14 & 252) >> 2];
            var6 = var3 + 1;
            var4[var3] = (char)var12[((var14 & 3) << 4) + ((var15 & 240) >> 4)];
            var1 = var6 + 1;
            var4[var6] = (char)var12[(var15 & 15) << 2];
            var4[var1] = (char)32;
         }

         return new String(var4);
      } else {
         return "";
      }
   }
```

明显是个base64，b是自定义的字母表，复制代码直接运行一边就可以得到字母表`9SKj8BfvJD5PcdH+Rh7TIbXwgpC/Nntiq62rWUEaAzQ3ZyVFG4mLoY0l1xOeMkus`

最后将base64之后的字母表直接传入lib里的a函数，ida打开

```cpp
int __fastcall Java_com_example_re3_MainActivity_a(_JNIEnv *a1, int a2, int a3)
{
  const char *v3; // r0
  signed int i; // [sp+24h] [bp-34h]
  int v6; // [sp+28h] [bp-30h]
  signed int v7; // [sp+2Ch] [bp-2Ch]
  const char *v8; // [sp+30h] [bp-28h]
  _JNIEnv *v9; // [sp+3Ch] [bp-1Ch]

  v9 = a1;
  v8 = (const char *)t(a1, a3);
  v7 = strlen(v8);
  v6 = _JNIEnv::NewStringUTF(v9, (const char *)&unk_171B0);
  r = 0;
  for ( i = 0; i < v7; ++i )
    a(v8[i]);
  sub_99CC();
  b((N *)r);
  if ( sub_99E2(&result, "00235CFPaeefijlmnrwz") )
    return v6;
  sub_99CC();
  bb((N *)r);
  if ( sub_99E2(&result, "020C5PaeeFlmnjzwrif3") )
    return v6;
  sub_99CC();
  bbb((N *)r);
  v3 = (const char *)sub_99FC(&result);
  return _JNIEnv::NewStringUTF(v9, v3);
}
```

经过三个函数b，bb，bbb的处理，前两个用于判断，最后一个用于输出

```cpp
int __fastcall b(int result)
{
  N **v1; // [sp+4h] [bp-Ch]

  v1 = (N **)result;
  if ( result )
  {
    b(*(N **)(result + 4));
    sub_95C8(&::result, *(unsigned __int8 *)v1);
    result = b(v1[2]);
  }
  return result;
}

int __fastcall bb(int result)
{
  N **v1; // [sp+4h] [bp-Ch]

  v1 = (N **)result;
  if ( result )
  {
    bb(*(N **)(result + 4));
    bb(v1[2]);
    result = sub_95C8(&::result, *(unsigned __int8 *)v1);
  }
  return result;
}

int __fastcall bbb(int result)
{
  int v1; // [sp+4h] [bp-Ch]

  v1 = result;
  if ( result )
  {
    sub_95C8(&::result, *(unsigned __int8 *)result);
    bbb(*(N **)(v1 + 4));
    result = bbb(*(N **)(v1 + 8));
  }
  return result;
}
```

三个经典的递归调用遍历，分别对应中序、后序和先序遍历，所以整个的过程可以看成按照输入建一棵二叉树，然后已知中序和后序，求先序遍历的结果，先手算了一遍然后跑一遍模板验算了一下

```cpp
#include <iostream>

using namespace std;

void beford(string in, string after) {
    if (in.size() > 0) {
        char ch = after[after.size() - 1];
        cout << ch;
        int k = in.find(ch);
        beford(in.substr(0, k), after.substr(0, k));
        beford(in.substr(k + 1), after.substr(k, in.size() - k - 1));；
    }
}

int main() {
    string inord = "00235CFPaeefijlmnrwz", aftord = "020C5PaeeFlmnjzwrif3";
    beford(inord, aftord);
    cout << endl;
    return 0;
}
```

输出结果就是flag

```
flag{3020fF5CeaPeirjnmlwz}
```

甚至可以不用管输入是什么……



