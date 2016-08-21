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
     int total = 4;
     //total = getTotal();
     char *lista[total];
     int i = 0;	 

     printf("\n Chegou em getFuncoes %p %d",lista,total);
     getFuncoes(lista);
     //printf("\nlista[0] == [%s]\n",lista[0]);		

     printf("\nTotal: %d %p\n",total,lista);
     lua_createtable(L, 0, total);
     for(i=0;i<total;i++){
	     printf("\nEstou na iteracao : %d [%s]\n",i,lista[i]);	
	     lua_pushnumber(L, i+1);
	     printf("\nPassei do pushnumber\n");
	     lua_pushstring(L, lista[i]);
	     printf("\nPassei do pushstring\n");
	     lua_settable(L, -3); 
	     printf("\npassei do lua_settable\n");
     }
     printf("\nTerminou ");
     //int a = lua_tointeger(L, 1);  
     //int b = lua_tointeger(L, 2);
     //int r = execute(a,b);
     //lua_pushnumber(L, r);
     return 1;
 }

static int mw_getTotal(lua_State *L){
	
	int total = getTotal();
	return total;
}
 
 static int mw_executar(lua_State *L){
    DIR *dir = NULL;
    void *lib_handle[100];
    int (*f_todas);  
   
    int a = lua_tointeger(L, 1); 
    lua_pushnumber(L,a); 
    printf("\npassei do push a");
    int b = lua_tointeger(L, 2);
    lua_pushnumber(L,b);
    printf("\npassei do push b");
    int op = lua_tointeger(L,3);
    lua_pushnumber(L,op);  
    printf("\npassei do push op");
    printf("\n a[%d]b[%d]op[%d]",a,b,op);
    int r = executar(a,b,op);
    printf("\n Passou pelo executar");
    lua_pushnumber(L, r);
    printf("\n passou pelo push r");
     return r;	
    
   
//(int v1,int v2,int op)
 }
 
 static const struct luaL_Reg wrapper[] = {
     
 //{"execute",mw_execute},
 {"getFuncoes",mw_getFuncoes},
 {"executar",mw_executar},
 {"getTotal",mw_getTotal},	
 {NULL,NULL}};
 
 int luaopen_wrapper(lua_State *L){
	luaL_register(L,"wrapper",wrapper);

	return 1;
 }
 
 

 
 




