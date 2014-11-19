#include "pgsampler.h"

/* List of databases */
char* database_list(void) {
	char* result;
  StringInfoData query;
    
  initStringInfo(&query);
  appendStringInfo(&query, "SELECT datname, datconnlimit, datfrozenxid, now()::text as m_at FROM pg_database WHERE datistemplate is not true;");  
  result = exec_to_command("DBLIST", query.data);
  
  return result;  
}
