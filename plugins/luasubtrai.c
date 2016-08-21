#include <lua.h>                               
#include <lauxlib.h>
#include <lualib.h>                             /* Always include this when calling Lua */

#include <stdlib.h>                             /* For function exit() */
#include <stdio.h>   
int execute(int i, int j){
	lua_State *L;

	L = luaL_newstate();                        /* Create Lua state variable */
	luaL_openlibs(L);                           /* Load Lua libraries */

	luaL_loadfile(L, "../plugins/luasubtrai.lua");
	lua_pcall(L,0,0,0);
	lua_getglobal(L,"subtrai");

	lua_pushnumber(L,i);
	lua_pushnumber(L,j);
	lua_pcall(L,2,1,0);
	int z = lua_tonumber(L,-1);
	lua_pop(L,1);

return z;
} 
