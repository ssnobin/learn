#include <stdio.h>
#include <unistd.h>

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
//gcc -o asdf testprint.c /usr/local/lib/liblua.a  -ldl  -lm
void printstack(lua_State * L){
    int top = lua_gettop(L);
    printf("==========================%d\n", top);
    for (int i=1; i<=top; i++)
    {
        int type = lua_type(L,i);

        if (type == LUA_TNUMBER){
            int value = lua_tonumber(L, i);
            printf("%d ",value);
        }
        else if(type == LUA_TSTRING){
            const char *s = lua_tostring(L, i);
            printf("%s ",s);
        }
        else if(type == LUA_TFUNCTION){
            printf("function is %d", type); // 6 is userdata
        }
        else if(type == LUA_TUSERDATA){
            printf("userdata is %d", type);
        }
    }
    printf("\n");
}
int main(int argc, const char *argv[]){
    lua_State *L = luaL_newstate();
    if (L==NULL) {
        perror("failed");
        return -1;
    }
    luaL_openlibs(L);
    printstack(L);
    if (luaL_loadfile(L, "./testprint.lua")){
        perror("gg");
        return -1;
    }
    printstack(L);
    lua_pcall(L, 0, 0, 0);
    printf("**************");
    printstack(L);
    lua_pushnumber(L, 5);
    lua_getglobal(L, "printmsg");
    printf("**************");
    printstack(L);
    lua_pcall(L, 0, 0, 0);
    printf("**************");
    printstack(L);

    lua_pushnumber(L, 5);
    printstack(L);
    int a = lua_tonumber(L, -1);
    //printf("a is %d\n", a);
    printstack(L);

    lua_pushstring(L, "helloworld");
    //const char * s = lua_tostring(L, -1);
    //printf("s is %s\n", s);
    printstack(L);

    // int b = lua_tonumber(L, -2);
    // printf("now the integer becomes 2nd %d\n", b);

    // int type = lua_type(L, -1); //4 is TSTRING
    // printf("type is %d\n", type);

    // int top = lua_gettop(L);
    // printf("top is %d\n", top);

    lua_pushvalue(L, 2);
    printstack(L);

    lua_getglobal(L, "add");
    printstack(L);

    lua_pushnumber(L, 99);
    lua_pushnumber(L, 98);
    printstack(L);
    lua_pcall(L, 2, 1, 0);
    printstack(L);
    
    lua_close(L);
    return 0;
}