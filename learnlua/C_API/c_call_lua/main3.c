//gcc -o main3 main3.c /usr/local/lib/liblua.a -ldl -lm
#include        <stdio.h>
#include        <string.h>
#include        "lua.h"
#include        "lualib.h"
#include        "lauxlib.h"
  
lua_State* L = NULL;  
  
static int myAdd(lua_State *L)  
{  
    //获取2个参数检查参数是否是number  
    int x= luaL_checknumber(L, 1);  
    int y= luaL_checknumber(L, 2);  
    //c++实际完成的工作  
    int c = x + y;  
    //计算结果进栈  
    lua_pushnumber(L, c);  
    //因为要返回一个参数，所以要return 1  
    return 1;  
}  
  
int main (int argc, char **argv) {  
    //开启lua状态机  
    L = luaL_newstate();  
    //装载lua库  
    luaL_openlibs(L);  
    //将函数注册到lua  
    lua_register(L, "myAdd", myAdd);  
    //执行脚本  
    luaL_dofile(L, "hello.lua");  
    //system("pause");  
    //关闭lua状态机  
    lua_close(L);  
    //return EXIT_SUCCESS;  
}  

// #include <stdio.h>
// #include <string.h>
// #include "lua.h"
// #include "lauxlib.h"
// #include "lualib.h"

// lua_State *L = NULL;

// //待注册的C函数。
// static int myadd(lua_State* L)
// {
//     //double op1 = lua_tonumber(L,1);//获取参数，1表示Lua调用时的第一个参数(从左到右)
//     //检查栈中的参数是否是数字，不是则抛出错误信息
//     double op1 = luaL_checknumber(L,1);
//     double op2 = luaL_checknumber(L,2);

//     //将函数的结果压入栈中。如果有多个返回值，可以在这里多次压入栈中。
//     lua_pushnumber(L,op1 + op2);

//     //压入返回值结果数量
//     return 1;
// }

// //另一个待注册的C函数。
// static int mysub(lua_State* L)
// {
//     double op1 = luaL_checknumber(L,1);
//     double op2 = luaL_checknumber(L,2);
//     lua_pushnumber(L,op1 - op2);
//     return 1;
// }

// //const char* testluacode = "print(myadd(100,20)) print(mysub(99,20))";

// int main(void){
//     L = luaL_newstate();//打开Lua,创建一个新环境(新的Lua状态)
//     luaL_openlibs(L); //打开标准库, 如: print, pcall

//     //lua_pushcfunction(L,myadd);//压入函数
//     //lua_setglobal(L,"myadd");//赋值全局变量

//     //和以下等价,将指定的函数注册为Lua的全局函数变量
//     //第一个参数为Lua在调用C函数时的全局函数名，第二个参数为实际C函数的指针。
//     lua_register(L, "myadd", myadd);
//     lua_register(L, "mysub", mysub);

//     //在Lua的代码块中使用已注册的C函数
//     // if (luaL_dostring(L,testluacode))
//     //     printf("Failed to invoke.\n");
//     luaL_dofile(L, "hello.lua");
//     lua_close(L);
//     return 0;
// }