//
// Created by Nathan on 23/03/2018.
//

#ifndef HASHTABLE_HASHFUNC_H
#define HASHTABLE_HASHFUNC_H

namespace Nathan {
    class HashFunc {
    public:
        static unsigned int hashInt(const int& key,unsigned int range) {
            return key % range;
        }
    };
}

#endif //HASHTABLE_HASHFUNC_H
