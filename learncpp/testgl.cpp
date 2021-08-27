#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

#include <SDL2/SDL.h> 
#include <GL/gl.h> 

int main(int argc, char *argv[]) 
{ 
        int final_status = 1; 
        SDL_Window *window; 
        SDL_GLContext openGL_context; 

        if (SDL_Init(SDL_INIT_VIDEO)) { 
                fprintf(stderr, "Unable to initialize SDL: %s\n", 
                        SDL_GetError()); 
                return 1; 
        } 
        window = SDL_CreateWindow("My Demo", SDL_WINDOWPOS_CENTERED, 
                                  SDL_WINDOWPOS_CENTERED, 640, 480, 
                                  SDL_WINDOW_OPENGL); 
        if (!window) { 
                fprintf(stderr, "Can't create window: %s\n", SDL_GetError()); 
                goto finished; 
        } 

        openGL_context = SDL_GL_CreateContext(window); 
        if (!openGL_context) { 
                fprintf(stderr, "Can't create openGL context: %s\n", 
                        SDL_GetError()); 
                goto close_window; 
        } 

        /* drawing code removed */ 

        final_status = 0; 
        SDL_GL_DeleteContext(openGL_context); 
close_window: 
        SDL_DestroyWindow(window); 
finished: 
        SDL_Quit(); 
        fprintf(stdout, "done\n"); 
        fflush(stdout); 
        return final_status; 
}  
