#include <iostream>
#include <chrono>
#include <unistd.h> 
#include <iomanip>
#include <stdlib.h> 



std::time_t get_current_time(int delta_minutes = 0){
    auto now = std::chrono::system_clock::now();
    now += std::chrono::minutes(delta_minutes);
    return std::chrono::system_clock::to_time_t(now);
}

void display_ellapsed_time(int time_elapsed_seconds){
    int hours = time_elapsed_seconds / 3600;
    int minutes = (time_elapsed_seconds % 3600) / 60;
    int seconds = time_elapsed_seconds % 60;
    std::cout << "Time Remaining -> " 
            << std::setfill('0') << std::setw(2) << hours << ":"
            << std::setfill('0') << std::setw(2) << minutes << ":"
            << std::setfill('0') << std::setw(2) << seconds << std::endl;
}

void run_timer(int duration_minutes){
    int duration_seconds = duration_minutes * 60;
    const std::time_t start_time = get_current_time();
    const std::time_t end_time = get_current_time(duration_minutes);

    while(true){
            sleep(1);
            auto diff_time = get_current_time() - start_time;
            int seconds_remaining = duration_seconds - diff_time;
            system("clear"); 
            std::cout << "Starting time " << std::ctime(&start_time);
            std::cout << "Ending time " << std::ctime(&end_time);
            display_ellapsed_time(seconds_remaining);
            if(seconds_remaining <= 0){
                break;
            }
        }

    system("clear");
    std::cout << "Session has finished!" << std::endl;
}

int main(){
    while(true){
        std::cout << "Please enter amount of minutes for the current session. Enter 0 to exit." << std::endl;
        int minutes;
        std::cin >> minutes;
        if(minutes == 0){
            break;
        }
        std::cout << minutes << " minutes entered. Press enter to start." << std::endl;
        std::cin;
        run_timer(minutes);
    }

    return 0;
}
