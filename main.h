#ifndef __MAIN_H__
#define __MAIN_H__

#define SUCCESS 0
#define FAILURE 1


typedef struct {
    char *ffmpeg;
    char *lame;
} conversion_data;


#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <glib.h>

int process_handler(char *cmd);
void destroy(GtkWidget *widget, gpointer data);
void gui(int argc, char **argv);
void picker(GtkWidget *widget, gpointer data);
void install_dependencies_thread();
void install();
void *conversion_thread(gpointer user_data);

#endif
