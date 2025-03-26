#include "../include/dffos.h"
#include <stdio.h>


#if defined(__WIN64__) || defined(__WIN32__)
    #include <windows.h>
    
    size_tll get_total_storage_memory(RRS_UNIT unit){
        ULARGE_INTEGER totalNumberOfBytes;
        if (!GetDiskFreeSpaceEx(NULL, NULL, &totalNumberOfBytes, NULL)) {
            #ifndef _rrasms_disable_warning_messages_
                perror("Failed to get disk space");
            #endif
        }
        unsigned long long totalsize = totalNumberOfBytes.QuadPart;
        switch(unit){
            case BYTE: break;
            case KILOBYTE: totalsize /= 1024; break;
            case MEGABYTE: totalsize /= (1024 * 1024); break;
            case GIGABYTE: totalsize /= (1024 * 1024 * 1024); break;
            default: invalid_unit(); break;
        return totalsize;
        }
    }

    size_tll get_free_storage_memory(RRS_UNIT unit){
        ULARGE_INTEGER totalNumberOfFreeBytes;
        
        if (!GetDiskFreeSpaceEx(NULL, NULL, NULL, &totalNumberOfFreeBytes)) {
            #ifndef _rrasms_disable_warning_messages_
                perror("Failed to get disk space");
            #endif
        }

        unsigned long long availablesize = totalNumberOfFreeBytes.QuadPart;
        switch(unit){
            case BYTE: break;
            case KILOBYTE: availablesize /= 1024; break;
            case MEGABYTE: availablesize /= (1024 * 1024); break;
            case GIGABYTE: availablesize /= (1024 * 1024* 1024); break;
            default: invalid_unit(); break;
        return availablesize;
        }
    }

#elif defined(__unix__)
    #include <sys/statvfs.h>

    void error_reading_drive_data(){
        #ifndef _rrasms_disable_warning_messages_
            perror("Error when retrieving drive information!");
        #endif
    }

    size_tll get_total_storage_memory(RRS_UNIT unit){
    struct statvfs fsStats;

    if (statvfs("/", &fsStats) != 0) { error_reading_drive_data();}
    
    unsigned long long totalSize = (unsigned long long)fsStats.f_blocks * fsStats.f_frsize;

        switch(unit){
            case BYTE: break;
            case KILOBYTE: totalSize /= 1024; break;
            case MEGABYTE: totalSize /= (1024 * 1024); break;
            case GIGABYTE: totalSize /= (1024 * 1024 * 1024); break;
            default: invalid_unit(); break;
        return totalSize;
        }
    }
    


    size_tll get_free_storage_memory(RRS_UNIT unit){
        struct statvfs fsStats;

        if (statvfs("/", &fsStats) != 0) { error_reading_drive_data();}
    
        unsigned long long freeSize = (unsigned long long)fsStats.f_bfree * fsStats.f_frsize;

        switch(unit){
            case BYTE: break;
            case KILOBYTE: freeSize /= 1024; break;
            case MEGABYTE: freeSize /= (1024 * 1024); break;
            case GIGABYTE: freeSize /= (1024 * 1024 * 1024); break;
            default: invalid_unit(); break;
        return freeSize;
        }
    }

#else
    #error "Sorry, this library does not support this operating system!"
#endif