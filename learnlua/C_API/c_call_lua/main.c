#include <stdio.h>
#include <string.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
//gcc -o mainmain main.c /usr/local/lib/liblua.a -ldl -lm
int main(void){
    char buff[256];
    int error;
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    while(fgets(buff, sizeof(buff), stdin)!=NULL){
        error = luaL_loadstring(L,buff)||lua_pcall(L,0,0,0);
        if (error) {
            fprintf(stderr, "%s\n", lua_tostring(L,-1));
            lua_pop(L,1);
        }
    }
    lua_close(L);
    return 0;
}
