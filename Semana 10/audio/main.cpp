// para utilizarlo en ubuntu instalar los siguientes paquetes para SDL_mixer:
// sudo apt-get install libsdl-mixer1.2-dev libsdl1.2-dev

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cerr << "Debe ejecutar el programa de la siguiente manera: "
			<< argv[0] << " <archivo .mp3>" << endl;
		return -1;
	}

	const char* archivo = "botanik.mp3";

	// inicializar
	if (SDL_Init(SDL_INIT_AUDIO) != 0)
	{
		cerr << "Error an inicializar en SDL_Init!" << endl;
		return -1;
	}

	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 2048) != 0)
	{
		cerr << "Error al abrir devices en Mix_OpenAudio! " << Mix_GetError() << endl;
		return -1;
	}

	// volumen
	Mix_VolumeMusic(100);

	// abrir archivo de audio (.mp3)
	Mix_Music* music = Mix_LoadMUS(archivo);

	if (music)
	{
		// empezar a reproducir
		if (Mix_PlayMusic(music, 1) == 0)
		{
			unsigned int startTime = SDL_GetTicks();
		 
			// esperar mientras termina de reproducirse el archivo
			cout << "Reproduciendo " << archivo << endl;
			while (Mix_PlayingMusic())
			{
			SDL_Delay(1000);
			cout << "Time: " << (SDL_GetTicks() - startTime) / 1000 << endl;
			}
		}
		else
		{
			cerr << "Mix_PlayMusic ERROR: " << Mix_GetError() << endl;
		}

		// cerrar archivo
		Mix_FreeMusic(music);
		music = NULL;
	}
	else
	{
		cerr << "Mix_LoadMuS ERROR: " << Mix_GetError() << endl;
	}
	
	// terminar
	Mix_CloseAudio();
	return 0;
}