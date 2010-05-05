

inline void gcollect(Session *sess, RefData* gc_save_point, RefChain *res, size_t gc_save_count ){
    sess->gc_exclude(res);
    sess->gc_clean(gc_save_point);
}
