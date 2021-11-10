# Gold Magic 800 3D Game
# 2018, Etqan Company
# 2018, Mahmoud Fayed <msfclipper@yahoo.com>

class GameSound

	lUseSound = True 
	lUseMusic = True 

	lSoundFilesLoaded = False

	BackGroundMusic BackGroundSampleID
	lMusic = False 

	PointSound  PointSampleID
	lPlayPointSound = False

	HitSound  HitSampleID
	lPlayHitSound = True

	StorySound  StorySampleID
	lPlayStorySound = True

	MenuChangeSound  MenuChangeSampleID
	lPlayMenuChangeSound = True

	MenuClickSound  MenuClickSampleID
	lPlayMenuClickSound = True

	lPlayLevelSound = True 

	func LoadSound

		if lSoundFilesLoaded return ok
	 	lSoundFilesLoaded = True

		BackGroundMusic = al_load_sample("sound/music3.wav")
		CheckFatalError(BackGroundMusic,"Can't load the sound file sound/music3.wav")
		PointSound = al_load_sample("sound/sfx_point.wav")
		CheckFatalError(PointSound,"Can't load the sound file sound/sfx_point.wav")
		HitSound = al_load_sample("sound/sfx_hit.wav")
		CheckFatalError(HitSound,"Can't load the sound file sound/sfx_hit.wav")
		StorySound = al_load_sample("sound/storymusic.wav")
		CheckFatalError(StorySound,"Can't load the sound file sound/storymusic.wav")
		MenuChangeSound = al_load_sample("sound/menuchange2.wav")
		CheckFatalError(MenuChangeSound,"Can't load the sound file sound/menuchange2.wav")
		MenuClickSound = al_load_sample("sound/menuclick2.wav")
		CheckFatalError(MenuClickSound,"Can't load the sound file sound/menuclick2.wav")


	func SoundOnOff

		lUseSound = ! lUseSound
		lPlayHitSound = ! lPlayHitSound 
		lPlayLevelSound = ! lPlayLevelSound
		lPlayMenuChangeSound = ! lPlayMenuChangeSound
		lPlayMenuClickSound = ! lPlayMenuClickSound		

	func MusicOnOff

		lUseMusic = ! lUseMusic 
		if lUseMusic 
			PlayBackGroundMusic()
			lMusic = False 
		else 
			al_stop_sample(BackGroundSampleID)
		ok


	func PlayBackGroundMusic

		if lMusic = False 
			BackGroundSampleID = al_new_allegro_sample_id()
			al_play_sample(BackGroundMusic, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,BackGroundSampleID)
			lMusic = True 
		ok

	func PlayPointSound

		if lPlayPointSound = False return ok
		if IsNULL(PointSampleID)
			PointSampleID = al_new_allegro_sample_id()
			al_play_sample(PointSound, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,PointSampleID)
		ok

	func StopPointSound

		if lPlayPointSound = False return ok
		if not ISNULL(PointSampleID)
			al_stop_sample(PointSampleID)
			PointSampleID = NULL
		ok

	func PlayHitSound

		if lPlayHitSound = False return ok
		if IsNULL(HitSampleID)
			HitSampleID = al_new_allegro_sample_id()
			al_play_sample(HitSound, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,HitSampleID)
		ok

	func StopHitSound

		if lPlayHitSound = False return ok
		if not ISNULL(HitSampleID)
			al_stop_sample(HitSampleID)
			HitSampleID = NULL
		ok

	func PlayMenuChangeSound

		if lPlayMenuChangeSound = False return ok
		if IsNULL(MenuChangeSampleID)
			MenuChangeSampleID = al_new_allegro_sample_id()
			al_play_sample(MenuChangeSound, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,MenuChangeSampleID)
		ok

	func StopMenuChangeSound

		if lPlayMenuChangeSound = False return ok
		if not ISNULL(MenuChangeSampleID)
			al_stop_sample(MenuChangeSampleID)
			MenuChangeSampleID = NULL
		ok

	func PlayMenuClickSound

		if lPlayMenuClickSound = False return ok
		if IsNULL(MenuClickSampleID)
			MenuClickSampleID = al_new_allegro_sample_id()
			al_play_sample(MenuClickSound, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,MenuClickSampleID)
		ok

	func StopMenuClickSound

		if lPlayMenuClickSound = False return ok
		if not ISNULL(MenuClickSampleID)
			al_stop_sample(MenuClickSampleID)
			MenuClickSampleID = NULL
		ok


	func PlayStorySound

		if lPlayStorySound = False return ok
		if IsNULL(StorySampleID)
			StorySampleID = al_new_allegro_sample_id()
			al_play_sample(StorySound, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,StorySampleID)
		ok

	func StopStorySound

		if lPlayStorySound = False return ok
		if not ISNULL(StorySampleID)
			al_stop_sample(StorySampleID)
			StorySampleID = NULL
		ok

	func PlayLevelSound

		if lPlayLevelSound
			LevelSampleID = al_new_allegro_sample_id()
			al_play_sample(PointSound, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,LevelSampleID)
		ok

	func Destroy 

		al_destroy_sample(StorySound)
		al_destroy_sample(BackGroundMusic)
		al_destroy_sample(PointSound)
		al_destroy_sample(HitSound)
