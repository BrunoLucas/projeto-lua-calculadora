#include <stdio.h>
#include <string.h>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include <dlfcn.h>
#include <dirent.h>
//#include "../lib/plugin.h"

 
 static int mw_execute(lua_State *L){
     int a = lua_tointeger(L, 1);  
     int b = lua_tointeger(L, 2);
     int r = 0; //execute(a,b);
     lua_pushnumber(L, r);
     return 1;
 }
 
  static int mw_getFuncoes(lua_State *L){
     char **lista;
     printf("\n Chegou em getFuncoes");
     lista = getFuncoes();	
     printf("\n retornou de getFuncoes");
     lua_createtable(L, 0, 0);
     lua_pushstring(L, lista[0]);
     lua_pushnumber(L, 1);
     lua_settable(L, -3); 
     printf("\nTerminou ");
     //int a = lua_tointeger(L, 1);  
     //int b = lua_tointeger(L, 2);
     //int r = execute(a,b);
     //lua_pushnumber(L, r);
     return 1;
 }
 static int mw_executar(lua_State *L){
    DIR *dir = NULL;
    void *lib_handle[100];
    int (*f_todas);  
    
    int a = lua_tointeger(L, 1);  
    int b = lua_tointeger(L, 2);
    int op = lua_tointeger(L,3);  
    int r = executar(a,b,op);
    lua_pushnumber(L, r);
     return r;	
    
   
//(int v1,int v2,int op)
 }
 
 static const struct luaL_Reg wrapper[] = {
     
 //{"execute",mw_execute},
 {"getFuncoes",mw_getFuncoes},
 {"executar",mw_executar},	
 {NULL,NULL}};
 
 int luaopen_wrapper(lua_State *L){
	luaL_register(L,"wrapper",wrapper);

	return 1;
 }
 
 

 
 




