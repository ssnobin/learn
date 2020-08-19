#include<stdio.h>
#include<string.h>
#include<lua.h>
#include<lauxlib.h>
#include<lualib.h>
//gcc -fPIC -shared -o abc.so test.c
int add(lua_State* L)   //去掉了原代码中的extern "C"，后面也是类似去掉了
{
    double op1 = luaL_checknumber(L, 1);
    double op2 = luaL_checknumber(L, 2);
    lua_pushnumber(L, op1 + op2);
    return 1;
}
 
int sub(lua_State* L)
{
    double op1 = luaL_checknumber(L, 1);
    double op2 = luaL_checknumber(L, 2);
    lua_pushnumber(L, op1 - op2);
    return 1;
}

int get(lua_State* L)
{
    //{watcherid:={"A"={maker1={e='A',id=xx,x=xx,y=xx},},"D"={},"U"={}}}
    printf("element num:%d\n",lua_gettop(L));
    lua_newtable(L);
    printf("element num:%d\n",lua_gettop(L));

    int evt_id = 1;
    int idx_ret = lua_gettop(L);
    lua_rawgeti(L, idx_ret, evt_id);
    printf("idx_ret is %d\n", idx_ret);
    if(lua_isnil(L, -1)) {
        printf("idx_ret is nil\n");
        lua_pop(L, 1);
        lua_newtable(L);
        //lua_newtable(L);
        lua_pushvalue(L, -1);
        printf("element here:%d\n",lua_gettop(L));
        lua_rawseti(L, idx_ret, evt_id);
        printf("element there:%d\n",lua_gettop(L));
    }

    int idx_evt_set = lua_gettop(L);
    printf("idx_evt_set is %d\n", idx_evt_set);
    lua_Integer marker_id = 1;
    lua_rawgeti(L, idx_evt_set, marker_id);
    if(lua_isnil(L, -1)) {
        printf("idx_evt_set is nil\n");
        lua_pop(L, 1);
        lua_newtable(L);
        //lua_newtable(L);
        lua_pushvalue(L, -1);
        lua_rawseti(L, idx_evt_set, marker_id);
    }
    printf("element gg:%d\n",lua_gettop(L));
    size_t len = lua_rawlen(L, -1);
    printf("len is %lu\n",len);
    lua_pushinteger(L, 2);
    lua_rawseti(L, -2, len+1);
    lua_pop(L, 2); // pop watcher_id_list and evt_set
    return 1;
}

int hello(lua_State* L)
{
    //{watcherid:={"A"={maker1={e='A',id=xx,x=xx,y=xx},},"D"={},"U"={}}}
    printf("element num:%d\n",lua_gettop(L));
    lua_newtable(L);
    printf("element num:%d\n",lua_gettop(L));

    int evt_id = 1;
    int idx_ret = lua_gettop(L);
    lua_rawgeti(L, idx_ret, evt_id);
    printf("idx_ret is %d\n", idx_ret);
    if(lua_isnil(L, -1)) {
        printf("idx_ret is nil\n");
        lua_pop(L, 1);
        lua_newtable(L);
        //lua_newtable(L);
        lua_pushvalue(L, -1);
        printf("element here:%d\n",lua_gettop(L));
        lua_rawseti(L, idx_ret, evt_id);
        printf("element there:%d\n",lua_gettop(L));
    }

    int idx_evt_set = lua_gettop(L);
    printf("idx_evt_set is %d\n", idx_evt_set);
    lua_Integer marker_id = 1;
    lua_rawgeti(L, idx_evt_set, marker_id);
    if(lua_isnil(L, -1)) {
        printf("idx_evt_set is nil\n");
        lua_pop(L, 1);
        lua_newtable(L);
        //lua_newtable(L);
        lua_pushvalue(L, -1);
        lua_rawseti(L, idx_evt_set, marker_id);
    }
    printf("element gg:%d\n",lua_gettop(L));
    size_t len = lua_rawlen(L, -1);
    printf("len is %lu\n",len);
    lua_pushinteger(L, 2);
    lua_rawseti(L, -2, len+1);
    lua_pop(L, 2); // pop watcher_id_list and evt_set
    return 1;
}

int wtf(lua_State* L)
//返回一个table1，其中table1中的value也是table2，并且是table2是同一个，只是引用
{
    //{1={4,5},2={4,5}}
    lua_newtable(L);
    //创建table{4,5}
    lua_newtable(L);
    lua_pushinteger(L, 4);
    lua_rawseti(L, -2, 1);
    lua_pushinteger(L, 5);
    lua_rawseti(L, -2, 2);

    //1={4,5}
    lua_rawseti(L, -2, 1);
    //2={4,5}
    lua_rawgeti(L, -1, 1);
    lua_rawseti(L, -2, 2);
    lua_pushinteger(L,100);
    return 2;
}
//luaL_Reg结构体的第一个字段为字符串，在注册时用于通知Lua该函数的名字。
//第一个字段为C函数指针。
//结构体数组中的最后一个元素的两个字段均为NULL，用于提示Lua注册函数已经到达数组的末尾。
static luaL_Reg mylibs[] ={
    {"add", add},
    {"sub", sub},
    {"get", get},
    {"hello", hello},
    {"wtf",wtf},
    {NULL, NULL}
};
//该C库的唯一入口函数。其函数签名等同于上面的注册函数。见如下几点说明：
//1. 我们可以将该函数简单的理解为模块的工厂函数。
//2. 其函数名必须为luaopen_xxx，其中xxx表示library名称。Lua代码require "xxx"需要与之对应。
//3. 在luaL_setfuncs的调用中，其第二个参数为待注册函数的数组。
//4. 需要强调的是，所有需要用到"xxx"的代码，不论C还是Lua，都必须保持一致，这是Lua的约定，
//   否则将无法调用。
int luaopen_abc(lua_State* L)
{
    //const char* libName = "mytestlib"; //
    //luaL_register(L, libName, mylibs); //由于在lua-5.3中已没有luaL_register这个函数，所以换成下面两行代码
    lua_newtable(L);
    luaL_setfuncs(L, mylibs, 0); 
 
    return 1;

}