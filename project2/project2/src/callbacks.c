#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "stdio.h"
#include "sql.h"
#include "sqlext.h"
#include "string.h"

struct student
{
	int roll;
	char name[20];
	char branch[15];
};

void
on_add_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *t1,*t2,*t3;
	char *roll,*name,*branch;
	SQLHENV p;
	SQLHDBC q;
	SQLHSTMT r;
	struct student m ;

	t1=lookup_widget(GTK_WIDGET(button),"entry1");	
	t2=lookup_widget(GTK_WIDGET(button),"entry2");	
	t3=lookup_widget(GTK_WIDGET(button),"entry3");	
	roll=gtk_entry_get_text(t1);
	name=gtk_entry_get_text(t2);
	branch=gtk_entry_get_text(t3);
	m.roll=atoi(roll);
	strcpy(m.name,name);
	strcpy(m.branch,branch);
		printf("%d %s %s\n",roll,name,branch);
		SQLAllocHandle(SQL_HANDLE_ENV,0,&p);
		SQLSetEnvAttr(p,SQL_ATTR_ODBC_VERSION,SQL_OV_ODBC3,0);
		SQLAllocHandle(SQL_HANDLE_DBC,p,&q);
		SQLAllocHandle(SQL_HANDLE_STMT,q,&r);
		SQLConnect(q,"college",strlen("college"),"root",strlen("root"),"",strlen(""));
		char x[]="use college;";
		SQLPrepare(r,x,strlen(x));
		char y[]="insert into student values(?,?,?)";
		SQLPrepare(r,y,strlen(y));
		SQLBindParameter(r,1,SQL_PARAM_INPUT,SQL_INTEGER,SQL_C_LONG,4,0,&m.roll,sizeof(m.roll),0);
		SQLBindParameter(r,2,SQL_PARAM_INPUT,SQL_CHAR,SQL_C_CHAR,20,0,m.name,strlen(m.name),0);
		SQLBindParameter(r,3,SQL_PARAM_INPUT,SQL_CHAR,SQL_C_CHAR,15,0,m.branch,strlen(m.branch),0);
		SQLTransact(p,q,SQL_COMMIT);
		SQLExecute(r);
		SQLFreeHandle(SQL_HANDLE_STMT,r);
		SQLDisconnect(q);
		SQLFreeHandle(SQL_HANDLE_DBC,q);
		SQLFreeHandle(SQL_HANDLE_ENV,p);
		gtk_entry_set_text(t1,"");
		gtk_entry_set_text(t2,"");
		gtk_entry_set_text(t3,"");
		gtk_widget_grab_focus(t1);
}

void
on_exit_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_main_quit();
}

