#include <lua.h>                        //Lua语言解析器
#include <lualib.h>                     //Lua标准库
#include <lauxlib.h>                    //Lua辅助工具
//gcc -o mainmain2 main2.c /usr/local/lib/liblua.a -ldl -lm
char *code = "for i=0, 5 do print(\'Hello, world!\') end";

int main() {
    lua_State *s = luaL_newstate();         //建立一个虚拟机
    luaL_openlibs(s);                       //打开Lua附加库
    luaL_dostring(s, code);         //执行字符串中的源代码
    lua_close(s);                   //关闭虚拟机
    return 0;
}
