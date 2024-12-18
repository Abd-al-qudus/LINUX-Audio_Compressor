#include "main.h"
#include <glib.h>
#include <gtk/gtk.h>

//conversion block structure
typedef struct {
    char *ffmpeg;
    char *lame;
} conversion_data;


//function signatures
void gui(int argc, char **argv);
void destroy(GtkWidget *widget, gpointer data);
void picker(GtkWidget *widget, gpointer data);
void *conversion_thread(gpointer user_data);


/**
 * main - call other functions
 * @ac: argument count
 * @av: argument vector
 * @envr: environment variables
 * Return: 0 always success
 */

int main(int ac, char **av)
{
    gui(ac, av);
    return (SUCCESS);
}


/**
 * gui - handles the gui operation
 * @argc: argument count
 * @argv: argument array
 * Return: void
 */

void gui(int argc, char **argv)
{
    GtkWidget *window, *convert_button, *install_button, *box, *label;
    GtkTextBuffer *buffer;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Audio Converter");

    box = gtk_vbox_new(FALSE, 20);
    label = gtk_label_new("LINUX Audio Converter and Compressor - (MP3)");
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);


    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window), 50);

    // "Convert Audio" button
    convert_button = gtk_button_new_with_label("Convert & Compress");
    g_signal_connect(convert_button, "clicked", G_CALLBACK(picker), NULL);
    gtk_box_pack_start(GTK_BOX(box), convert_button, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_widget_show_all(window);
    gtk_main();
}


/**
 * destroy - destroy a gui session
 * @widget: widget object to destroy
 * @data: gpointer data
 * Return: void
 */

void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}


/**
 * picker - pick an audio file and extract its file path
 * this initaites the conversion process for a new threaded
 * schedule to allow destruction of the dialog
 * @widget: button widget triggering the dialog
 * @data: gpointer data
 * Return: void
 */

void picker(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog;
    gint res;

    dialog = gtk_file_chooser_dialog_new("Select Audio File",
                                         NULL,
                                         GTK_FILE_CHOOSER_ACTION_OPEN,
                                         "_Cancel", GTK_RESPONSE_CANCEL,
                                         "_Open", GTK_RESPONSE_ACCEPT,
                                         NULL);

    res = gtk_dialog_run(GTK_DIALOG(dialog));
    if (res == GTK_RESPONSE_ACCEPT)
    {
        conversion_data *conv_data;
        GtkFileChooser *chooser;
        char *ffmpeg_buffer, *lame_buffer, *filepath, *filename;

        ffmpeg_buffer = malloc(sizeof(char) * 1024);
        lame_buffer = malloc(sizeof(char) * 1024);
        chooser = GTK_FILE_CHOOSER(dialog);
        filepath = gtk_file_chooser_get_filename(chooser);

        g_print("File selected: %s\n", filepath);

        strcpy(ffmpeg_buffer, "ffmpeg -y -i ");
        strcat(ffmpeg_buffer, filepath);
        strcat(ffmpeg_buffer, " -vn -acodec libmp3lame temp.mp3");

        filename = strrchr(filepath, '/') + 1;
        strcpy(lame_buffer, "lame -b 16 temp.mp3 ");
        strcat(lame_buffer, filename);

        g_free(filepath);
        gtk_widget_destroy(dialog);

        conv_data = malloc(sizeof(conversion_data));
        conv_data->ffmpeg = ffmpeg_buffer;
        conv_data->lame = lame_buffer;
        g_thread_new("conversion_thread", conversion_thread, conv_data);
    }
    else
        gtk_widget_destroy(dialog);
}


/**
 * conversion_thread - allows widget destruction by creating
 * or initaiting the conversion process in a new thread,
 * this allows non blocking I/O
 * Return: true of false
 */

void *conversion_thread(gpointer user_data)
{
    conversion_data *data;
    int pc;

    data = (conversion_data *)user_data;
    process_handler(data->ffmpeg);
    free(data->ffmpeg);

    process_handler(data->lame);
    free(data->lame);

    pc = process_handler("rm temp.mp3");

    free(data);
    if (pc == SUCCESS)
        printf("Conversion sucessful\n");
    return (NULL);
}
