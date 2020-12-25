/*  Sample Programs
 * 
 *  From: https://github.com/Mysticial/Pokemon-Automation-SwSh-Arduino-Scripts
 * 
 */

#include <iostream>
#include "Common/PushButtons.h"
#include "Common/PokemonRoutines.h"
#include "Common/PokemonProgramIDs.h"
#include "Connection/SerialConnection.h"
#include "Libraries/MessageConverter.h"
#include "Libraries/Logging.h"
#include "Programs.h"

namespace PokemonAutomation{


std::unique_ptr<PABotBase> start_connection(
    bool require_pabotbase,
    const std::string& device_name,
    MessageLogger* logger
){
    std::unique_ptr<PABotBase> pabotbase;
    if (device_name.empty()){
        std::string name;
        std::cout << "Please enter the name of the serial connection." << std::endl;
        std::cout << std::endl;
#if _WIN32
        std::cout << "If you don't know what it is, go to Device Manager -> Ports (COM & LPT)" << std::endl;
        std::cout << "The name should be something like, \"COM5\"." << std::endl;
#else
        std::cout << "If you don't know what it is, type \"ls /sys/class/tty\" to list them." << std::endl;
        std::cout << "The name should be something like, \"/dev/ttyUSB0\"." << std::endl;
#endif
        std::cout << std::endl;
        std::cout << "Device Name: ";
        std::cin >> name;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Connecting to device... (" << name << ")" << std::endl;
        pabotbase = std::make_unique<PABotBase>(
            std::make_unique<SerialConnection>(name, PABB_BAUD_RATE), logger
        );
    }else{
        pabotbase = std::make_unique<PABotBase>(
            std::make_unique<SerialConnection>(device_name, PABB_BAUD_RATE), logger
        );
    }

    std::cout << "Verifying protocol compatibility..." << std::endl;
    uint32_t version = pabotbase->protocol_version();
    uint32_t version_hi = version / 100;
    uint32_t version_lo = version % 100;
    if (version_hi != PABB_PROTOCOL_VERSION / 100 || version_lo < PABB_PROTOCOL_VERSION % 100){
        throw "Incompatible version. Client: " + std::to_string(PABB_PROTOCOL_VERSION) + ", Device: " + std::to_string(version);
    }
    std::cout << std::endl;

    uint8_t program_id = pabotbase->program_id();
    std::cout << "Program ID:       " << (unsigned)program_id << " (" << program_name(program_id) << ")" << std::endl;

    uint32_t program_version = pabotbase->program_version();
    std::cout << "Program Version:  " << program_version << std::endl;

    uint32_t wallclock = pabotbase->system_clock();
    std::cout << "Device Up Time:   " << wallclock << " ticks (" << (double)wallclock / TICKS_PER_SECOND << " seconds)" << std::endl;
    std::cout << std::endl;

    if (require_pabotbase && program_id != PABB_PID_PABOTBASE){
        throw "The device must be running PABotBase for this program to work.";
    }

//    std::cout << "Begin Message Logging..." << std::endl;
//    pabotbase->add_message_snooper(logger);

    return pabotbase;
}


void device_logger(const std::string& device_name){
    std::cout << "Starting Device Logger..." << std::endl;
    std::cout << std::endl;
    std::unique_ptr<PABotBase> pabotbase = start_connection(false, device_name);
    global_connection = pabotbase.get();

    std::cout << "Begin Message Logging..." << std::endl;
    MessageLogger logger;
    pabotbase->add_message_snooper(logger);


    //  Wait Forever
    while (true){
        std::string x;
        std::cin >> x;
    }
}


//
//  Settings copied from the Arduino program files:
//      FrameworkSettings.h
//      PokemonSettings.h
//
const uint16_t CONNECT_CONTROLLER_DELAY         =   5 * TICKS_PER_SECOND;
const bool     TOLERATE_SYSTEM_UPDATE_MENU_FAST =   true;
const uint16_t OVERWORLD_TO_MENU_DELAY          =   120;
const uint16_t HOME_TO_GAME_DELAY               =   3 * TICKS_PER_SECOND;
const uint16_t GAME_TO_HOME_DELAY_FAST          =   100;
const uint16_t GAME_TO_HOME_DELAY_SAFE          =   125;


void program_TurboA(const std::string& device_name){
    std::cout << "Starting PABotBase - TurboA..." << std::endl;
    std::cout << std::endl;
    std::unique_ptr<PABotBase> pabotbase = start_connection(true, device_name);
    global_connection = pabotbase.get();

    std::cout << "Begin Message Logging..." << std::endl;
    MessageLogger logger;
    pabotbase->add_message_snooper(logger);


    //  Start Program
    start_program_flash(CONNECT_CONTROLLER_DELAY);
    grip_menu_connect_go_home();
    resume_game_no_interact(TOLERATE_SYSTEM_UPDATE_MENU_FAST);

    while (true){
        pbf_press_button(BUTTON_A, 5, 5);
//        std::cout << pabotbase->system_clock() << std::endl;
    }
}
void program_ClothingBuyer(const std::string& device_name){
    std::cout << "Starting PABotBase - ClothingBuyer..." << std::endl;
    std::cout << std::endl;
    std::unique_ptr<PABotBase> pabotbase = start_connection(true, device_name);
    global_connection = pabotbase.get();

    std::cout << "Begin Message Logging..." << std::endl;
    MessageLogger logger;
    pabotbase->add_message_snooper(logger);



    //  Rotate categories. This will allow the program to eventually buy out the
    //  entire store, but it will take a lot longer than doing separate runs on
    //  each category individually.
    const bool CATEGORY_ROTATION    =   true;



    //  Start Program
    start_program_flash(CONNECT_CONTROLLER_DELAY);
    grip_menu_connect_go_home();
    resume_game_no_interact(TOLERATE_SYSTEM_UPDATE_MENU_FAST);

    while (true){
        pbf_press_button(BUTTON_A, 10, 90);
        if (CATEGORY_ROTATION){
            pbf_press_dpad(DPAD_RIGHT, 10, 40);
        }
        pbf_press_button(BUTTON_A, 10, 90);
        pbf_press_button(BUTTON_A, 10, 90);
        pbf_press_dpad(DPAD_DOWN, 10, 40);
    }
}
void program_BallThrower(const std::string& device_name){
    std::cout << "Starting PABotBase - Ballthrower..." << std::endl;
    std::cout << std::endl;
    std::unique_ptr<PABotBase> pabotbase = start_connection(true, device_name);
    global_connection = pabotbase.get();

    std::cout << "Begin Message Logging..." << std::endl;
    MessageLogger logger;
    pabotbase->add_message_snooper(logger);



    //  Start Program
    start_program_flash(CONNECT_CONTROLLER_DELAY);
    grip_menu_connect_go_home();
    pbf_press_button(BUTTON_HOME, 10, HOME_TO_GAME_DELAY);

    while (true){
        pbf_press_button(BUTTON_X, 50, 50);
        pbf_press_button(BUTTON_A, 50, 50);
        pbf_press_button(BUTTON_B, 50, 50);
    }

//    pbf_press_button(BUTTON_HOME, 10, GAME_TO_HOME_DELAY_SAFE);
//    end_program_callback();
//    end_program_loop();
}
void program_BeamReset(const std::string& device_name){
    std::cout << "Starting PABotBase - BeamReset..." << std::endl;
    std::cout << std::endl;
    std::unique_ptr<PABotBase> pabotbase = start_connection(true, device_name);
    global_connection = pabotbase.get();

    std::cout << "Begin Message Logging..." << std::endl;
    MessageLogger logger;
    pabotbase->add_message_snooper(logger);



    //  Wait in the Home menu for this long before resetting the game.
    const uint16_t DELAY_BEFORE_RESET   =   5 * TICKS_PER_SECOND;

    //  Talking to the den has an extra line in German. Set this to true if this
    //  is the case.
    const bool EXTRA_LINE   =   false;



    //  Start Program
    start_program_flash(CONNECT_CONTROLLER_DELAY);
    grip_menu_connect_go_home();

    resume_game_front_of_den_nowatts(TOLERATE_SYSTEM_UPDATE_MENU_FAST);
    pbf_mash_button(BUTTON_B, 100);

    while (true){
        //  Talk to den.
        pbf_press_button(BUTTON_A, 10, 450);
        if (EXTRA_LINE){
            pbf_press_button(BUTTON_A, 10, 300);
        }
        pbf_press_button(BUTTON_A, 10, 300);

        //  Drop wishing piece.
        pbf_press_button(BUTTON_A, 10, 70);
        pbf_press_button(BUTTON_HOME, 10, GAME_TO_HOME_DELAY_FAST);

        for (uint16_t c = 0; c < 4; c++){
            pbf_press_button(BUTTON_HOME, 10, 10);
            pbf_press_button(BUTTON_HOME, 10, 220);
        }
        pbf_wait(DELAY_BEFORE_RESET);

        reset_game_from_home(TOLERATE_SYSTEM_UPDATE_MENU_FAST, 0, false);
    }

    end_program_callback();
    end_program_loop();
}
void program_FriendDelete(const std::string& device_name){
    std::cout << "Starting PABotBase - FriendDelete..." << std::endl;
    std::cout << std::endl;
    std::unique_ptr<PABotBase> pabotbase = start_connection(true, device_name);
    global_connection = pabotbase.get();

    std::cout << "Begin Message Logging..." << std::endl;
    MessageLogger logger;
    pabotbase->add_message_snooper(logger);



    //  Set to a large number to delete all friends.
    const uint16_t FRIENDS_TO_DELETE    =   3;

    //  Instead of deleting friends, block them.
    const bool BLOCK_FRIENDS            =   false;

    //  Timings: You may need to increase if your internet is slow.
    const uint16_t VIEW_FRIEND_DELAY    =   2 * TICKS_PER_SECOND;   //  Delay from opening a friend to when you can press buttons.
    const uint16_t DELETE_FRIEND_DELAY  =   4 * TICKS_PER_SECOND;   //  Delay to delete the friend.
    const uint16_t FINISH_DELETE_DELAY  =   2 * TICKS_PER_SECOND;   //  Delay after deleting a friend.



    //  Start Program
    start_program_flash(CONNECT_CONTROLLER_DELAY);
    pbf_press_button(BUTTON_A, 5, 5);

    for (uint16_t c = 0; c < FRIENDS_TO_DELETE; c++){
        pbf_press_button(BUTTON_A, 5, VIEW_FRIEND_DELAY);       //  View friend
        pbf_press_dpad(DPAD_DOWN, 5, 5);
        pbf_press_button(BUTTON_A, 10, 90);                     //  Click on Options
        if (BLOCK_FRIENDS){
            pbf_press_dpad(DPAD_DOWN, 5, 5);
        }
        pbf_press_button(BUTTON_A, 10, 90);                     //  Click on Remove/Block Friend
        if (BLOCK_FRIENDS){
            pbf_press_button(BUTTON_A, 5, VIEW_FRIEND_DELAY);   //  Confirm 
        }
        pbf_press_button(BUTTON_A, 5, DELETE_FRIEND_DELAY);     //  Confirm 
        pbf_press_button(BUTTON_A, 5, FINISH_DELETE_DELAY);     //  Finish delete friend.
    }

    end_program_callback();
    end_program_loop();
}
void program_DateSpam_WattFarmer(const std::string& device_name){
    std::cout << "Starting PABotBase - DateSpam-WattFarmer..." << std::endl;
    std::cout << std::endl;
    std::unique_ptr<PABotBase> pabotbase = start_connection(true, device_name);
    global_connection = pabotbase.get();

    std::cout << "Begin Message Logging..." << std::endl;
    MessageLogger logger;
    pabotbase->add_message_snooper(logger);



    //  Grab watts this many times. You can set this number if you're also date
    //  skipping to a particular den frame and you don't want to overshoot it.
    //
    //  Be aware that this program isn't intended to be an accurate date skipper.
    //  It will occasionally miss frames causing it to fall short.
    const uint32_t SKIPS            =   33334;

    //  Save the game every this number of iterations.
    //  If set to zero, no saving is done.
    const uint16_t SAVE_ITERATIONS  =   0;



//    start_program_flash(CONNECT_CONTROLLER_DELAY);
    grip_menu_connect_go_home();

    uint16_t save_count = 0;
    for (uint32_t c = 0; c < SKIPS; c++){
//        pabb_send_info_i32(c);
        log("Frames Skipped: " + std::to_string(c));
        home_roll_date_enter_game_autorollback(10);
        pbf_mash_button(BUTTON_B, 90);

        pbf_press_button(BUTTON_A, 5, 5);
        pbf_mash_button(BUTTON_B, 215);

        if (SAVE_ITERATIONS != 0){
            save_count++;
            if (save_count >= SAVE_ITERATIONS){
                save_count = 0;
                pbf_mash_button(BUTTON_B, 2 * TICKS_PER_SECOND);
                pbf_press_button(BUTTON_X, 20, OVERWORLD_TO_MENU_DELAY);
                pbf_press_button(BUTTON_R, 20, 2 * TICKS_PER_SECOND);
                pbf_press_button(BUTTON_ZL, 20, 3 * TICKS_PER_SECOND);
            }
        }

        //  Tap HOME and quickly spam B. The B spamming ensures that we don't
        //  accidentally update the system if the system update window pops up.
        pbf_press_button(BUTTON_HOME, 10, 5);
        pbf_mash_button(BUTTON_B, GAME_TO_HOME_DELAY_FAST - 15);
    }

    end_program_callback();
    end_program_loop();
}




}
