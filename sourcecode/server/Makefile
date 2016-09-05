################################################################################################/

bin/server:obj/four_gearless_db.o  obj/four_gear_db.o  obj/two_gearless_db.o  obj/two_gear_db.o  obj/vehicle_class.o  obj/tw.o obj/tw_gear.o  obj/main_server.o obj/logger.o obj/inotify.o obj/bikeHandler.o
	g++ -std=c++0x -o bin/server obj/four_gearless_db.o  obj/four_gear_db.o  obj/two_gearless_db.o  obj/two_gear_db.o  obj/vehicle_class.o  obj/tw.o obj/tw_gear.o  obj/main_server.o  obj/logger.o obj/inotify.o obj/bikeHandler.o -lpthread 

obj/logger.o:
	g++ -std=c++0x -c -g -o obj/logger.o src/logger.cpp -Iinclude/ -I3rdpartyTools/strtk 

obj/main_server.o: 
	g++ -std=c++0x -c -g -o obj/main_server.o src/main_server.cpp -Iinclude/ -Iinclude/database/ -Iinclude/handlers/ -I3rdpartyTools/strtk  

obj/inotify.o:
	g++ -std=c++0x -c -g -o obj/inotify.o src/inotify.cpp -Iinclude/ -I3rdpartyTools/strtk  -Iinclude/database/ -lpthread

obj/four_gearless_db.o:  
	g++ -std=c++0x -c -g -o obj/four_gearless_db.o src/database/four_gearless_db.cpp -Iinclude/ -Iinclude/database/ -I3rdpartyTools/strtk

obj/four_gear_db.o: 
	g++ -std=c++0x -c -g -o obj/four_gear_db.o src/database/four_gear_db.cpp -Iinclude/ -Iinclude/database/ -I3rdpartyTools/strtk

obj/two_gearless_db.o: 
	g++ -std=c++0x -c -g -o obj/two_gearless_db.o src/database/two_gearless_db.cpp -Iinclude/ -Iinclude/database/ -I3rdpartyTools/strtk

obj/two_gear_db.o: 
	g++ -std=c++0x -c -g -o obj/two_gear_db.o src/database/two_gear_db.cpp -Iinclude/ -Iinclude/database/ -I3rdpartyTools/strtk

obj/tw_gear.o: 
	g++ -std=c++0x -c -g -o obj/tw_gear.o src/tw_gear.cpp -Iinclude/ 

obj/tw.o: 
	g++ -std=c++0x -c -g -o obj/tw.o src/tw.cpp -Iinclude/ 

obj/bikeHandler.o: 
	g++ -std=c++0x -c -g -o obj/bikeHandler.o src/handlers/bikeHandler.cpp -Iinclude/ -Iinclude/database/ -Iinclude/handlers/ -I3rdpartyTools/strtk 

obj/vehicle_class.o: 
	g++ -std=c++0x -c -g -o obj/vehicle_class.o src/vehicle_class.cpp -Iinclude/ 

clean:
	-rm -f obj/*
	-rm -f bin/*

################################################################################################
