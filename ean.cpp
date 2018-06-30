#include <gtk/gtk.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include "obliczenia.hpp"
#include "Iobliczenia.hpp"



using namespace std;

const string funkcja1 = "b*pow(x,2)+a*x-7";
const string funkcja2 = "a+b*sin(x)";
const string funkcja3 = "a*pow(0.9,x)*sin(x)-b";
const string parametr_A = "1";
const string parametr_B = "1";
const string ograniczenie_1 = "0,00001";
const string ograniczenie_2 = "0,00001";
const string ograniczenie_3 = "500";
const string przedzial_lewy = "0";
const string przedzial_prawy = "10";



GtkWidget *entry_A;
GtkWidget *entry_B;
GtkWidget *entry_O1;
GtkWidget *entry_O2;
GtkWidget *entry_O3;
GtkWidget *entry_PL;
GtkWidget *entry_PP;
GtkWidget *checkbox_W1;
GtkWidget *checkbox_W2;
GtkWidget *wybierz_funkcje;



void chart2(long double a, long double b, long double x0, int funkcja, long double lp, long double pp) {

  //system("gnome-terminal -e \"python3 graph.py\"");

  char a_char[70], b_char[70], x0_char[70],funkcja_char[10], spacja[2] = " ", koniec[2] = "\"", lp_char[70], pp_char[70];

  sprintf(a_char, "%Lf", a);
  sprintf(b_char, "%Lf", b);
  sprintf(x0_char, "%Lf", x0);
  sprintf(funkcja_char, "%d", funkcja);
  sprintf(lp_char, "%Lf", lp);
  sprintf(pp_char, "%Lf", pp);

  char komenda[440] = "gnome-terminal --command=\"python3 wykres.py ";

  strcat(komenda, a_char);
  strcat(komenda, spacja);
  strcat(komenda, b_char);
  strcat(komenda, spacja);
  strcat(komenda, x0_char);
  strcat(komenda, "_");
  strcat(komenda, lp_char);
  strcat(komenda, "_");
  strcat(komenda, pp_char);
  strcat(komenda, spacja);
  strcat(komenda, funkcja_char);;
  strcat(komenda, koniec);
  system(komenda);
}


void  Idane_konwertuj(string * dane){
  gchar *text =gtk_combo_box_get_active_text(GTK_COMBO_BOX(wybierz_funkcje));
  const gchar *text_entry_A =gtk_entry_get_text(GTK_ENTRY(entry_A));
  const gchar *text_entry_B =gtk_entry_get_text(GTK_ENTRY(entry_B));
  const gchar *text_entry_O1 =gtk_entry_get_text(GTK_ENTRY(entry_O1));
  const gchar *text_entry_O2 =gtk_entry_get_text(GTK_ENTRY(entry_O2));
  const gchar *text_entry_O3 =gtk_entry_get_text(GTK_ENTRY(entry_O3));
  const gchar *text_entry_PL =gtk_entry_get_text(GTK_ENTRY(entry_PL));
  const gchar *text_entry_PP =gtk_entry_get_text(GTK_ENTRY(entry_PP));


  char *e;
  dane[1] = text_entry_A, &e;
  dane[2] = text_entry_B, &e;
  dane[3] = text_entry_O1, &e;
  dane[4] = text_entry_O2, &e;
  dane[5] = text_entry_PL, &e;
  dane[6] = text_entry_PP, &e;
  dane[7] = text_entry_O3, &e;

  //funkcja
  if(text == funkcja1){
    dane[0] = "1";
  }else if(text == funkcja2){
      dane[0] = "2";
  }else if(text == funkcja3){
      dane[0] = "3";
  }

  //checkoxy
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkbox_W1)))
  {
    dane[8] = "1";
  }else dane[8] = "0";
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkbox_W2)))
  {
    dane[9] = "1";
  }else dane[9] = "0";

}


void  dane_konwertuj(long double * dane){
  gchar *text =gtk_combo_box_get_active_text(GTK_COMBO_BOX(wybierz_funkcje));
  const gchar *text_entry_A =gtk_entry_get_text(GTK_ENTRY(entry_A));
  const gchar *text_entry_B =gtk_entry_get_text(GTK_ENTRY(entry_B));
  const gchar *text_entry_O1 =gtk_entry_get_text(GTK_ENTRY(entry_O1));
  const gchar *text_entry_O2 =gtk_entry_get_text(GTK_ENTRY(entry_O2));
  const gchar *text_entry_O3 =gtk_entry_get_text(GTK_ENTRY(entry_O3));
  const gchar *text_entry_PL =gtk_entry_get_text(GTK_ENTRY(entry_PL));
  const gchar *text_entry_PP =gtk_entry_get_text(GTK_ENTRY(entry_PP));


  char *e;
  dane[1] = strtold(text_entry_A, &e);
  dane[2] = strtold(text_entry_B, &e);
  dane[3] = strtold(text_entry_O1, &e);
  dane[4] = strtold(text_entry_O2, &e);
  dane[5] = strtold(text_entry_PL, &e);
  dane[6] = strtold(text_entry_PP, &e);
  dane[7] = strtold(text_entry_O3, &e);

  //funkcja
  if(text == funkcja1){
    dane[0] = 1;
  }else if(text == funkcja2){
      dane[0] = 2;
  }else if(text == funkcja3){
      dane[0] = 3;
  }
  else{
    dane[0] = 1;
  }

  //checkoxy
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkbox_W1)))
  {
    dane[8] = 1;
  }else dane[8] = 0;
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkbox_W2)))
  {
    dane[9] = 1;
  }else dane[9] = 0;




}




void double_representation(long double * dane){

  GtkWidget *okno2;
  GtkWidget *kontener2;
  GtkWidget *etykieta_T;
  //GtkWidget *przycisk_wykres;

  long double wyniki[99999];
  int ile_wierszy;
  int * wsk_ile_wierszy = &ile_wierszy;


  oblicz(dane, wyniki, wsk_ile_wierszy);


  etykieta_T = gtk_label_new(gtk_combo_box_get_active_text(GTK_COMBO_BOX(wybierz_funkcje)));




  //stworzenie okna
  okno2 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_move (GTK_WINDOW(okno2), 0, 100);
  //tytuł okna
  gtk_window_set_title(GTK_WINDOW(okno2), "Reprezentacja double");



  //TWORZENIE
  kontener2 = gtk_vbox_new ( FALSE, 0);
  //przycisk_oblicz = gtk_button_new_with_label("WYKRES");
  //



  //WYMIARY
  gtk_widget_set_size_request(kontener2, 700, 700);
  //gtk_widget_set_size_request(przycisk_oblicz, 180, 35);
  //



  //POZYCJA
  gtk_container_add(GTK_CONTAINER(okno2), kontener2);
  gtk_window_set_position(GTK_WINDOW(okno2), GTK_WIN_POS_CENTER);
  gtk_fixed_put(GTK_FIXED(kontener2), etykieta_T, 230, 75);
  //gtk_fixed_put(GTK_FIXED(kontener2), przycisk_oblicz, 10, 250);
  //



  //PRZEIWJANA TABEL
  GtkWidget * przesuwne_okno;
  GtkWidget *tabela, *etykieta, *pole_tekstowe;
  guint i;
  przesuwne_okno = gtk_scrolled_window_new ( NULL, NULL );
  gtk_box_pack_start( GTK_BOX(kontener2), przesuwne_okno, TRUE, TRUE, 0 );

 tabela = gtk_table_new ( ile_wierszy, 1, FALSE );
 for ( i = 0; i < ile_wierszy; i++ )
 {
   stringstream stream;
   stream.setf( ios::scientific );
   stream<< scientific<< setprecision(16) << wyniki[i];
   string s = " x " + to_string(i) + " = " + stream.str();
   etykieta = gtk_label_new (&s[0]);
   gtk_table_attach_defaults( GTK_TABLE(tabela), etykieta, 10, 10+1, i+100, i+101 );

 }

 /* Dodaje tabele do przewijanego okna */
 gtk_scrolled_window_add_with_viewport ( GTK_SCROLLED_WINDOW(przesuwne_okno), tabela );




  //g_signal_connect(G_OBJECT(przycisk_oblicz), "clicked", G_CALLBACK(chart), NULL);

  gtk_widget_show_all(okno2);


  chart2(dane[1],dane[2],wyniki[ile_wierszy-1], (int)dane[0], dane[5], dane[6]);

}

void interval_representation(string * dane){
  GtkWidget *okno2;
  GtkWidget *kontener2;
  GtkWidget *etykieta_T;
  //GtkWidget *przycisk_wykres;

  string wyniki[99999];
  int ile_wierszy;
  int * wsk_ile_wierszy = &ile_wierszy;


  ioblicz(dane, wyniki, wsk_ile_wierszy);


  etykieta_T = gtk_label_new(gtk_combo_box_get_active_text(GTK_COMBO_BOX(wybierz_funkcje)));




  //stworzenie okna
  okno2 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_move (GTK_WINDOW(okno2), 1200, 100);
  //tytuł okna
  gtk_window_set_title(GTK_WINDOW(okno2), "Reprezentacja Interwałowa");



  //TWORZENIE
  kontener2 = gtk_vbox_new ( FALSE, 0);
  //przycisk_oblicz = gtk_button_new_with_label("WYKRES");
  //



  //WYMIARY
  gtk_widget_set_size_request(kontener2, 700, 700);
  //gtk_widget_set_size_request(przycisk_oblicz, 180, 35);
  //



  //POZYCJA
  gtk_container_add(GTK_CONTAINER(okno2), kontener2);
  gtk_window_set_position(GTK_WINDOW(okno2), GTK_WIN_POS_CENTER);
  gtk_fixed_put(GTK_FIXED(kontener2), etykieta_T, 230, 75);
  //gtk_fixed_put(GTK_FIXED(kontener2), przycisk_oblicz, 10, 250);
  //



  //PRZEIWJANA TABEL
  GtkWidget * przesuwne_okno;
  GtkWidget *tabela, *etykieta, *pole_tekstowe;
  guint i;
  przesuwne_okno = gtk_scrolled_window_new ( NULL, NULL );
  gtk_box_pack_start( GTK_BOX(kontener2), przesuwne_okno, TRUE, TRUE, 0 );

 tabela = gtk_table_new ( ile_wierszy, 1, FALSE );
 for ( i = 0; i < ile_wierszy; i++ )
 {
   string s = " x " + to_string(i) + " = " + wyniki[i];
   etykieta = gtk_label_new (&s[0]);
   gtk_table_attach_defaults( GTK_TABLE(tabela), etykieta, 10, 10+1, i+100, i+101 );

 }

 /* Dodaje tabele do przewijanego okna */
 gtk_scrolled_window_add_with_viewport ( GTK_SCROLLED_WINDOW(przesuwne_okno), tabela );



  gtk_widget_show_all(okno2);

}

void button_clicked(GtkWidget *widget, gpointer user_data) {
  long double dane[10];
  string idane[10];
  dane_konwertuj(dane);
  Idane_konwertuj(idane);



  double_representation(dane);
  interval_representation(idane);

}



int main (int argc, char *argv[]) {


  //interval_arithmetic::Interval<int> inter();



  GtkWidget *okno;
  GtkWidget *kontener;
  GtkWidget *przycisk_oblicz;
  GtkWidget *etykieta_A;
  GtkWidget *etykieta_B;
  GtkWidget *etykieta_F;
  GtkWidget *etykieta_O1;
  GtkWidget *etykieta_O2;
  GtkWidget *etykieta_O3;
  GtkWidget *etykieta_N1;


    gtk_init (&argc, &argv);

    //stworzenie okna
    okno = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    //tytuł okna
    gtk_window_set_title(GTK_WINDOW(okno), "Kurs GTK+");



    //TWORZENIE
    kontener = gtk_fixed_new();
    przycisk_oblicz = gtk_button_new_with_label("OBLICZ");
    etykieta_A = gtk_label_new("A");
    etykieta_B = gtk_label_new("B");
    etykieta_F = gtk_label_new("WYBÓR FUNKCJI");
    etykieta_O1 = gtk_label_new("OGRANICZENIE 1 ( |f(x)|<Ey )");
    etykieta_O2 = gtk_label_new("OGRANICZENIE 2 ( |xi-xi+1|<Ex )");
    etykieta_O3 = gtk_label_new("OGRANICZENIE 3 ( Liczba kroków )");
    etykieta_N1 = gtk_label_new("PRZEDZIAŁ");
    entry_A = gtk_entry_new();
    entry_B = gtk_entry_new();
    entry_O1 = gtk_entry_new();
    entry_O2 = gtk_entry_new();
    entry_O3 = gtk_entry_new();
    entry_PL = gtk_entry_new();
    entry_PP = gtk_entry_new();
    wybierz_funkcje = gtk_combo_box_new_text();
    gtk_combo_box_append_text(GTK_COMBO_BOX(wybierz_funkcje), &funkcja1[0]);
    gtk_combo_box_append_text(GTK_COMBO_BOX(wybierz_funkcje), &funkcja2[0]);
    gtk_combo_box_append_text(GTK_COMBO_BOX(wybierz_funkcje), &funkcja3[0]);
    checkbox_W1 = gtk_check_button_new_with_label ("Kontynuować nawet jeżeli funkcja na krańcach przedziału nie będzie mieć różnych znaków? (błąd 404)");
    checkbox_W2 = gtk_check_button_new_with_label ("Kontynuować nawet jeżeli funkcja na obu krańcach przedziału nie będzie spaełniała warunku f(x)*f``(x)>0? (błąd 503)");
    //

    //DOMYSLNE PARAMETRY
    gtk_entry_set_text(GTK_ENTRY(entry_A), &parametr_A[0]);
    gtk_entry_set_text(GTK_ENTRY(entry_B), &parametr_B[0]);
    gtk_entry_set_text(GTK_ENTRY(entry_O1), &ograniczenie_1[0]);
    gtk_entry_set_text(GTK_ENTRY(entry_O2), &ograniczenie_2[0]);
    gtk_entry_set_text(GTK_ENTRY(entry_O3), &ograniczenie_3[0]);
    gtk_entry_set_text(GTK_ENTRY(entry_PL), &przedzial_lewy[0]);
    gtk_entry_set_text(GTK_ENTRY(entry_PP), &przedzial_prawy[0]);
    gtk_combo_box_set_active(GTK_COMBO_BOX(wybierz_funkcje),0);



    //WYMIARY
    gtk_widget_set_size_request(kontener, 700, 600);
    gtk_widget_set_size_request(przycisk_oblicz, 200, 40);
    gtk_widget_set_size_request(wybierz_funkcje, 300, 40);
    gtk_widget_set_size_request(entry_A, 100, 40);
    gtk_widget_set_size_request(entry_B, 100, 40);
    gtk_widget_set_size_request(entry_O1, 500, 40);
    gtk_widget_set_size_request(entry_O2, 500, 40);
    gtk_widget_set_size_request(entry_O3, 200, 40);
    gtk_widget_set_size_request(entry_PL, 100, 40);
    gtk_widget_set_size_request(entry_PP, 100, 40);

    //



    //POZYCJA
    gtk_container_add(GTK_CONTAINER(okno), kontener);
    gtk_window_set_position(GTK_WINDOW(okno), GTK_WIN_POS_CENTER);
    gtk_fixed_put(GTK_FIXED(kontener), etykieta_F, 20, 10);
    gtk_fixed_put(GTK_FIXED(kontener), etykieta_A, 330, 10);
    gtk_fixed_put(GTK_FIXED(kontener), etykieta_B, 440, 10);
        gtk_fixed_put(GTK_FIXED(kontener), wybierz_funkcje, 10, 35);
        gtk_fixed_put(GTK_FIXED(kontener), entry_A, 320, 35);
        gtk_fixed_put(GTK_FIXED(kontener), entry_B, 430, 35);
    gtk_fixed_put(GTK_FIXED(kontener), etykieta_N1, 270, 100);
        gtk_fixed_put(GTK_FIXED(kontener), entry_PL, 10, 125);
        gtk_fixed_put(GTK_FIXED(kontener), entry_PP, 340, 125);
    gtk_fixed_put(GTK_FIXED(kontener), etykieta_O1, 20, 175);
        gtk_fixed_put(GTK_FIXED(kontener), entry_O1, 10, 200);
    gtk_fixed_put(GTK_FIXED(kontener), etykieta_O2, 20, 250);
        gtk_fixed_put(GTK_FIXED(kontener), entry_O2, 10, 275);
    gtk_fixed_put(GTK_FIXED(kontener), etykieta_O3, 20, 325);
        gtk_fixed_put(GTK_FIXED(kontener), entry_O3, 10, 350);
    gtk_fixed_put(GTK_FIXED(kontener), checkbox_W1, 10, 400);
    gtk_fixed_put(GTK_FIXED(kontener), checkbox_W2, 10, 425);
    gtk_fixed_put(GTK_FIXED(kontener), przycisk_oblicz, 250, 500);



    //

    //SYGNAŁY
    g_signal_connect(G_OBJECT(okno), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(przycisk_oblicz), "clicked", G_CALLBACK(button_clicked), NULL);



    gtk_widget_show_all(okno);


    gtk_main ();


    return 0;
}
