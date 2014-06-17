#include "flappy_box/view/box_audible.hpp"

using namespace ::flappy_box::view;

BoxAudible::BoxAudible()
{
	
	
	// Eine Geräuschquelle _al_box_source definieren mittels alGenSources und alSource3f, die
	// das Spielobjekt repräsentiert mit der Position 0.5[m] auf der x-Achse (rechte Seite) hat
	ALuint _al_box_source[2];
	alGenSources(1, _al_box_source);
	alSource3f(_al_box_source[0], AL_POSITION, flappy_box::model::Box::getPositionVec());

	// Einen Soundpuffer erzeugen mit 10[s]-anhaltender Sinusschwingung mit base_frequency 
	ALuint _al_box_buffer[2] = { alutCreateBufferWaveform(ALUT_WAVEFORM_SINE, base_frequency, 10000),
								 alutCreateBufferWaveform(ALUT_WAVEFORM_SINE, target_frequency, 10000) };
	alGenBuffers(1, _al_box_buffer);
	

	// Soundpuffer der Geräuschquelle zuweisen und Für Geräuschquelle die Wiedergabe in
	// Endlosschleife (AL_LOOPING) aufrufen
	alSourcei(_al_box_source[0], AL_LOOPING, _al_box_buffer[0]);

	// Wiedergabe der Geräuschquelle starten
	alSourcePlay(_al_box_source[0]);
}  

void BoxAudible::auralize(::view::AlRenderer&)
{

}
