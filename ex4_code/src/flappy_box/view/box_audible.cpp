# include "view/boxaudible.hpp"

BoxAudible()
{
      // Eine Geräuschquelle _al_box_source definieren mittels alGenSources und alSource3f
      alGenSources(1, alSource3f());
      
      // Einen Soundpuffer erzeugen mit 10[s]-anhaltender Sinusschwingung mit base_frequency 
      alGenBuffers();
      alutCreateBufferWaveform();
      
      // Soundpuffer der Geräuschquelle zuweisen
      alSourcei();
      
      // Für Geräuschquelle die Wiedergabe in Endlosschleife (AL_LOOPING) aufrufen
      
      // Wiedergabe der Geräuschquelle starten
      alSourcePlay();
}  

void auralize(view::AlRenderer&)
{

}
