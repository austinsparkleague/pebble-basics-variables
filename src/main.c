#include <pebble.h>
/*this is an example of how variables work in C.  For now, ignore all of the set up code for the app, and we are just going to focus on a small bit of
code that focuses on how you can store information in variables.*/
  
  
  
Window *my_window;
TextLayer *text_layer;

static void main_window_load(Window *window){
  //Here is where we are going to work for this project---------------------------------------
  //all programs store information in memory.  In order to do so, we first need to tell C,
  //what kind of information it should expect us to be storing in that variable.
  //The main reason for this is that different types of data will require different amounts of 
  //room in memory, and we want to be very specific so we don't set aside more than we need.
  //In most programming languages this is how you would declare a variable
  int some_integer = 4;
  
  //C is a very powerful language because it allows us to have a very nuanced control of our memory.
  //When storing Data, we also make heavy use of something called a "pointer"
  //This is a little tricky, but know for now that it helps us to set aside a chunk of memory, like so...
  char *i_am_a_word;
  
  //notice that we put an * in front of the name of this variable.  That is how we specify that something is a pointer.
  //so by entering "*i_am_a_word"" we are saying something like, "hey machine, I am going to need you to set aside enough memory for 
  //some text content, and from here on out, when I enter "i_am_a_word" I want you to plug in the value of whatever is in that chunk of memory that
  //you set aside." 
  
  //so now that we created a pointer to that bit of memory, we are going to assign a value to the memory that is being pointed to.
  i_am_a_word = "hello!";
  
  //How do you think we would go about changing the text that is stored inside the "i_am_a_word" variable?

  
 //------------------------------------------------------------------------------------------
  
  Layer *window_layer = window_get_root_layer(window);
  text_layer = text_layer_create(GRect(0, 0, 144, 60));
  text_layer_set_text(text_layer, i_am_a_word );
  text_layer_set_text_color(text_layer, GColorBlack);
  
  layer_add_child(window_layer, text_layer_get_layer(text_layer));

}

static void main_window_unload(){
   text_layer_destroy(text_layer);
}

void handle_init(void) {
  my_window = window_create();
 
  
  window_set_window_handlers(my_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload,
  });
  
  window_stack_push(my_window, true);
}

void handle_deinit(void) {
 window_destroy(my_window);
}


int main(void) {
  handle_init();
  app_event_loop();
  handle_deinit();
}
