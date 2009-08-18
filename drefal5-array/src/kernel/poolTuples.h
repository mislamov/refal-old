#ifndef REF_POOLTUPLES_INCLUDED
#define REF_POOLTUPLES_INCLUDED

#include "config.h"

class Session;


template <class T>
class DataLinkPooledStack {
	friend class Session;

	size_t idx;  // pool+idx - элемент после последнего; pool+0 - первый элемент; idx - кол-во элементов
	size_t size; // физическая длина пула
	T* pool;
public:
	DataLinkPooledStack(){
		idx = 0;
		size = POOLSIZE_DEFAULT;
		pool = (T*)malloc(sizeof(T)*size);
		if (!pool) RUNTIMEERROR("Mem-buffer", "memory limit");
		memset(pool, 0xff, sizeof(T)*size);
	};


	//~DataLinkPooledStack(){ free(pool); };
	void put(T l){
		if (idx >= size-1){
			size+=POOLSIZE_DEFAULT;
			pool = (T*)realloc(pool, sizeof(T)*size);
			if (!pool) RUNTIMEERROR("Mem-buffer", "memory limit");
		};
		pool[idx] = l;
		++idx;
	};

	T top_pop(){
		#ifdef TESTCODE
		if (!idx) SYSTEMERROR("link-stack is empty!");
		#endif
		return pool[--idx];
	};

	T top(){
		return pool[idx-1];
	};
	T getByIndex(size_t index){
		if (index <0 || index>=idx) return 0;
		return pool[index];
	}
	size_t getLength(){ return idx; }
	void clear(){
		idx = 0;
		size = POOLSIZE_DEFAULT;
		pool = (T*)realloc(pool, sizeof(T)*size);
		if (!pool) RUNTIMEERROR("Mem-buffer", "memory limit");
		memset(pool, 0xff, sizeof(T)*size);
	}
	void flush(){
		pool = (T*)realloc(pool, sizeof(T)*idx);
		if (!pool) RUNTIMEERROR("Mem-buffer", "memory limit");
	}
};



// Пулл-стек. сохраняет (put) и восстанавливает (top_pop) содержимое объектов типа T путем прямого копирования.

/*template <class T>
class PooledClass {
protected:
	T* pool;			// массив объетов. индексируется с 1. pool[0] - для служебного использования
    size_t last_ind;	// индекс последнего в стеке элемента
    size_t poolsize;	// индекс последнего в стеке элемента

public:
    PooledClass() {
        last_ind = 0;
        poolsize = POOLSIZE_DEFAULT;
        pool = (T*)malloc( sizeof(T)*POOLSIZE_DEFAULT );
		#ifdef TESTCODE
		memset(pool, 0xff, sizeof(T)*POOLSIZE_DEFAULT);
		#endif
    };

    ~PooledClass() {
        free(pool);
    };

    // сохраняет состояние item копированием
    void put_from(T* item) {
        ++last_ind ;
        if (last_ind >= poolsize) {
            // пул исчерпан
            LOG("T-pool is full. realloc!");
            poolsize += POOLSIZE_DEFAULT;
            pool = (T*) realloc(pool, poolsize*sizeof(T) );
            if (!pool) RUNTIMEERROR("T-pool", "not anouth memory");
			#ifdef TESTCODE
			memset(pool+last_ind, 0xff, sizeof(T)*POOLSIZE_DEFAULT);
			#endif
        }

		memcpy(pool+last_ind, item, sizeof(T));
        return;
    };

    void top_pop_to(T* item) {
        T* pool_last_ind = pool+last_ind;
		memcpy(item, pool_last_ind , sizeof(T));
		#ifdef TESTCODE
		memset(pool+last_ind, 0xff, sizeof(T));
		#endif
        --last_ind;

	};

    void clear() {
        last_ind = 0;
		#ifdef TESTCODE
		memset(pool, 0xff, sizeof(T)*poolsize);
		#endif
		memset(pool, 0xff, sizeof(T));
    };

};


*/

template <class T1, class T2>
class PooledTuple2 {
protected:
	struct TUPLE2 {T1 i1; T2 i2; };

	TUPLE2* pool;		// нумерация с 1
    size_t last_ind;	// индекс последнего в стеке элемента
    size_t poolsize;
public:
    PooledTuple2() {
		#ifdef TESTCODE
		if (sizeof(TUPLE2) != sizeof(T1)+sizeof(T2)) SYSTEMERROR("Platform depend collision! sizeof(TUPLE2) != sizeof( struct{T1 T2} ).");
		#endif

        last_ind = 0;
        poolsize = POOLSIZE_DEFAULT;
        pool = (TUPLE2*)malloc( sizeof(TUPLE2)*POOLSIZE_DEFAULT );
		#ifdef TESTCODE
		memset(pool, 0xff, sizeof(TUPLE2)*POOLSIZE_DEFAULT);
		#endif
    };

    ~PooledTuple2() {
        free(pool);
    };

    // сохраняет состояние item копированием
    void put(T1 i1, T2 i2) {
        ++last_ind ;
        if (last_ind >= poolsize) {
            // пул исчерпан
            //LOG("TUPLE2-pool is full. realloc!");
            poolsize += POOLSIZE_DEFAULT;
            pool = (TUPLE2*) realloc(pool, poolsize*sizeof(TUPLE2) );
            if (!pool) RUNTIMEERROR("TUPLE2-pool", "not anouth memory");

			#ifdef TESTCODE
			memset(pool+last_ind, 0xff, sizeof(TUPLE2)*POOLSIZE_DEFAULT);
			#endif
        }

		//memcpy(pool+last_ind,	{&i1,	sizeof(TUPLE2));
		TUPLE2* pool_last_ind = (TUPLE2*) pool+last_ind;
		pool_last_ind->i1 = i1;
		pool_last_ind->i2 = i2;
        return;
    };

    void top(T1 &i1, T2 &i2) {
        TUPLE2* pool_last_ind = pool + last_ind;
		i1 = pool_last_ind->i1;
		i2 = pool_last_ind->i2;
	};

	bool top_pop(T1 &i1, T2 &i2) {
		if (!last_ind) {i1=0;i2=0; return false;}
        top(i1,i2);
		#ifdef TESTCODE
		memset(pool+last_ind, 0xff, sizeof(TUPLE2));
		#endif
        --last_ind;
		return true;
	};

	size_t getLength(){ return last_ind; }

	bool getByIndex(size_t index, T1 &i1, T2 &i2){
		if (index<=0 || index>last_ind) {
			i1 = i2 = 0;
			return false;
		}
		TUPLE2* pool_index = pool + index;
		i1 = pool_index->i1;
		i2 = pool_index->i2;
		return true;
	}
	TUPLE2* findTopByFirstKey(T1 key){
		for(size_t i=last_ind; i; --i){
			if (pool[i].i1 == key) return pool+i;
		}
		return 0;
	}

    void clear() {
        last_ind = 0;
		#ifdef TESTCODE
		memset(pool, 0xff, sizeof(TUPLE2)*poolsize);
		#endif
		memset(pool, 0xff, sizeof(TUPLE2));
    };

};


template <class T1, class T2, class T3>
class PooledTuple3 {
protected:
	struct TUPLE3 {T1 i1; T2 i2; T3 i3;};

	TUPLE3* pool;		// нумерация с 1
    size_t last_ind;	// индекс последнего в стеке элемента
    size_t poolsize;
public:
    PooledTuple3() {
		#ifdef TESTCODE
		if (sizeof(TUPLE3) != sizeof(T1)+sizeof(T2)+sizeof(T3)) SYSTEMERROR("Platform depend collision! sizeof(TUPLE3) != sizeof( struct{T1 T2 T3} ).");
		#endif

        last_ind = 0;
        poolsize = POOLSIZE_DEFAULT;
        pool = (TUPLE3*)malloc( sizeof(TUPLE3)*POOLSIZE_DEFAULT );
		#ifdef TESTCODE
		memset(pool, 0xff, sizeof(TUPLE3)*POOLSIZE_DEFAULT);
		#endif
    };

    ~PooledTuple3() {
        free(pool);
    };

    // сохраняет состояние item копированием
    void put(T1 i1, T2 i2, T3 i3) {
        ++last_ind ;
        if (last_ind >= poolsize) {
            // пул исчерпан
            //LOG("TUPLE3-pool is full. realloc!");
            poolsize += POOLSIZE_DEFAULT;
            pool = (TUPLE3*) realloc(pool, poolsize*sizeof(TUPLE3) );
            if (!pool) RUNTIMEERROR("TUPLE3-pool", "not anouth memory");

			#ifdef TESTCODE
			memset(pool+last_ind, 0xff, sizeof(TUPLE3)*POOLSIZE_DEFAULT);
			#endif
        }

		//memcpy(pool+last_ind,	{&i1,	sizeof(TUPLE3));
		TUPLE3* pool_last_ind = (TUPLE3*) pool+last_ind;
		pool_last_ind->i1 = i1;
		pool_last_ind->i2 = i2;
		pool_last_ind->i3 = i3;
        return;
    };

    void top(T1 &i1, T2 &i2, T3 &i3) {
        TUPLE3* pool_last_ind = pool + last_ind;
		i1 = pool_last_ind->i1;
		i2 = pool_last_ind->i2;
		i3 = pool_last_ind->i3;
	};


	bool top_pop(T1 &i1, T2 &i2, T3 &i3) {
		if (!last_ind) {i1=0;i2=0;i3=0; return false;}
        top(i1,i2,i3);
		#ifdef TESTCODE
		memset(pool+last_ind, 0xff, sizeof(TUPLE3));
		#endif
        --last_ind;
		return true;
	};

	size_t getLength(){ return last_ind; }

	bool getByIndex(size_t index, T1 &i1, T2 &i2, T3 &i3){
		if (index<=0 || index>last_ind) {
			i1 = i2 = i3 = 0;
			return false;
		}
		TUPLE3* pool_index = pool + index;
		i1 = pool_index->i1;
		i2 = pool_index->i2;
		i3 = pool_index->i3;
		return true;
	}
	TUPLE3* findTopByFirstKey(T1 key){
		for(size_t i=last_ind; i; --i){
			if (pool[i].i1 == key) return pool+i;
		}
		return 0;
	}

    void clear() {
        last_ind = 0;
		#ifdef TESTCODE
		memset(pool, 0xff, sizeof(TUPLE3)*poolsize);
		#endif
		memset(pool, 0xff, sizeof(TUPLE3));
    };

};




template <class T1, class T2, class T3, class T4>
class PooledTuple4 {
protected:
	struct TUPLE4 {T1 i1; T2 i2; T3 i3; T4 i4; };

	TUPLE4* pool;       // нумерация с 1
    size_t last_ind;	// индекс последнего в стеке элемента
    size_t poolsize;

public:
    PooledTuple4() {
		#ifdef TESTCODE
		if (sizeof(TUPLE4) != sizeof(T1)+sizeof(T2)+sizeof(T3)+sizeof(T4)) SYSTEMERROR("Platform depend collision! sizeof(TUPLE4) != sizeof( struct{T1 T2 T3 T4} ).");
		#endif

        last_ind = 0;
        poolsize = POOLSIZE_DEFAULT;
        pool = (TUPLE4*)malloc( sizeof(TUPLE4)*POOLSIZE_DEFAULT );
		#ifdef TESTCODE
		memset(pool, 0xff, sizeof(TUPLE4)*POOLSIZE_DEFAULT);
		#endif
    };

    ~PooledTuple4() {
        free(pool);
    };

    // сохраняет состояние item копированием
    void put(T1 i1, T2 i2, T3 i3, T4 i4) {
        ++last_ind ;
        if (last_ind >= poolsize) {
            // пул исчерпан
            LOG("TUPLE4-pool is full. realloc!");
            poolsize += POOLSIZE_DEFAULT;
            pool = (TUPLE4*) realloc(pool, poolsize*sizeof(TUPLE4) );
            if (!pool) RUNTIMEERROR("TUPLE4-pool", "not anouth memory");

			#ifdef TESTCODE
			memset(pool+last_ind, 0xff, sizeof(TUPLE4)*POOLSIZE_DEFAULT);
			#endif
        }

		//memcpy(pool+last_ind,	{&i1,	sizeof(TUPLE4));
		TUPLE4* pool_last_ind = (TUPLE4*) pool+last_ind;
		pool_last_ind->i1 = i1;
		pool_last_ind->i2 = i2;
		pool_last_ind->i3 = i3;
		pool_last_ind->i4 = i4;
        return;
    };

    void top(T1 &i1, T2 &i2, T3 &i3, T4 &i4) {
        TUPLE4* pool_last_ind = pool + last_ind;
		i1 = pool_last_ind->i1;
		i2 = pool_last_ind->i2;
		i3 = pool_last_ind->i3;
		i4 = pool_last_ind->i4;
	};


	bool top_pop(T1 &i1, T2 &i2, T3 &i3, T4 &i4) {
		if (!last_ind) {i1=0;i2=0;i3=0; return false;}
        top(i1,i2,i3,i4);
		#ifdef TESTCODE
		memset(pool+last_ind, 0xff, sizeof(TUPLE4));
		#endif
        --last_ind;
		return true;
	};

	size_t getLength(){ return last_ind; }

	bool getByIndex(size_t index, T1 &i1, T2 &i2, T3 &i3, T4 &i4){
		if (index<=0 || index>last_ind) {
			i1 = i2 = i3 = i4 = 0;
			return false;
		}
		TUPLE4* pool_index = pool + index;
		i1 = pool_index->i1;
		i2 = pool_index->i2;
		i3 = pool_index->i3;
		i4 = pool_index->i4;
		return true;
	}

    void clear() {
        last_ind = 0;
		#ifdef TESTCODE
		memset(pool, 0xff, sizeof(TUPLE4)*poolsize);
		#endif
		memset(pool, 0xff, sizeof(TUPLE4));
    };

};






#endif // REF_POOLTUPLES_INCLUDED
