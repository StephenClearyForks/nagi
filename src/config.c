/* FUNCTION list 	---	---	---	---	---	---	---

*/

/* BASE headers	---	---	---	---	---	---	--- */
#include "agi.h"


/* LIBRARY headers	---	---	---	---	---	---	--- */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* OTHER headers	---	---	---	---	---	---	--- */
//#include "view/crap.h"
#include "sys/ini_config.h"
#include "config.h"
#include "sys/mem_wrap.h"


/* PROTOTYPES	---	---	---	---	---	---	--- */
//void test_function(void);

/* VARIABLES	---	---	---	---	---	---	--- */



/* CODE	---	---	---	---	---	---	---	--- */

void config_load(CONF *config, INI *ini)
{
	CONF *conf_ptr;
	u8 *key_data;
	
	conf_ptr = config;
	
	while (conf_ptr->key != 0)
	{
		if (conf_ptr->section != 0)
			ini_section(ini, conf_ptr->section);	// change to section
		
		// read_key = blah
		key_data = ini_key(ini, conf_ptr->key);
		
		if (key_data != 0)
		{
			switch (conf_ptr->type)
			{
				case CT_BOOL:
					*conf_ptr->b.ptr = (CONF_BOOL)(strtol(key_data, 0, 10) != 0);
					break;
				
				case CT_STRING:
					if (!strcmp(key_data, conf_ptr->s.def))
						*conf_ptr->s.ptr = conf_ptr->s.def;
					else
						*conf_ptr->s.ptr = strdup(key_data);
					break;
				
				case CT_INT: 
					*conf_ptr->i.ptr = (CONF_INT)strtol(key_data, 0, 10);
					if (*conf_ptr->i.ptr < conf_ptr->i.min)
						*conf_ptr->i.ptr = conf_ptr->i.min;
					else if (conf_ptr->i.max != -1)
							if (*conf_ptr->i.ptr > conf_ptr->i.max)
								*conf_ptr->i.ptr = conf_ptr->i.max;
					break;
							
				default:		// probably safest for defaults
					printf("config_read(): cannot determine type %d\n", conf_ptr->type);
			}
		}
		else
		{
			switch (conf_ptr->type)
			{
				case CT_BOOL: 
					*conf_ptr->b.ptr = conf_ptr->b.def;
					break;
				
				case CT_STRING: 
					*conf_ptr->s.ptr = conf_ptr->s.def;
					break;
				
				case CT_INT:  
					*conf_ptr->i.ptr = conf_ptr->i.def;
					break;
				
				default:		// probably safest for defaults
					printf("config_read(): cannot determine type %d\n", conf_ptr->type);
			}
		}
		conf_ptr++;
	}

}

void config_print(CONF *config)
{
	CONF *conf_ptr;
	
	conf_ptr = config;
	
	while (conf_ptr->key != 0)
	{
		switch (conf_ptr->type)
		{
			case CT_BOOL:
				printf("%s->%s = %ld\n", conf_ptr->section, conf_ptr->key,*conf_ptr->b.ptr );
				break;
			
			case CT_STRING:
				printf("%s->%s = %s\n", conf_ptr->section, conf_ptr->key, *conf_ptr->s.ptr );
				break;
			
			case CT_INT:
				printf("%s->%s = %ld\n", conf_ptr->section, conf_ptr->key,*conf_ptr->i.ptr );
				break;
			
			default:		// probably safest for defaults
				printf("config_read(): cannot determine type %d\n", conf_ptr->type);
		}
		conf_ptr++;
	}
	// close ini
}

void config_unload(CONF *config)
{
	CONF *conf_ptr;
	conf_ptr = config;
	
	while (conf_ptr->key != 0)
	{
		switch (conf_ptr->type)
		{
			case CT_STRING:
				if (strcmp(*conf_ptr->s.ptr, conf_ptr->s.def))
				{
					// if not using the default
					a_free(*conf_ptr->s.ptr);
				}
				break;
		}
		conf_ptr++;
	}
}