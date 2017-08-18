/*---------- begin exec-head.in ----------*/
/*! \file maxgrad.cxx
 *
 * Generated from maxgrad.diderot.
 *
 * Command: /Users/chariseechiw/diderot/chiw17/bin/diderotc --exec maxgrad.diderot
 * Version: vis15:2016-07-29
 */
/*---------- end exec-head.in ----------*/

#define DIDEROT_NO_INPUTS
#define DIDEROT_STRAND_ARRAY
/*---------- begin exec-incl.in ----------*/
#define DIDEROT_STANDALONE_EXEC
#define DIDEROT_SINGLE_PRECISION
#define DIDEROT_INT
#define DIDEROT_TARGET_SEQUENTIAL
#include "diderot/diderot.hxx"

#ifdef DIDEROT_ENABLE_LOGGING
#define IF_LOGGING(...)         __VA_ARGS__
#else
#define IF_LOGGING(...)
#endif
/*---------- end exec-incl.in ----------*/

// ***** Begin synthesized types *****

namespace Diderot {
    typedef float vec2 __attribute__ ((vector_size (8)));
    typedef float vec6 __attribute__ ((vector_size (32)));
    typedef float vec3 __attribute__ ((vector_size (16)));
    struct tensor_ref_3 : public diderot::tensor_ref<float,3> {
        tensor_ref_3 (const float *src);
        tensor_ref_3 (struct tensor_3 const & ten);
        tensor_ref_3 (tensor_ref_3 const & ten);
    };
    struct tensor_ref_2 : public diderot::tensor_ref<float,2> {
        tensor_ref_2 (const float *src);
        tensor_ref_2 (struct tensor_2 const & ten);
        tensor_ref_2 (tensor_ref_2 const & ten);
    };
    struct tensor_ref_2_2 : public diderot::tensor_ref<float,4> {
        tensor_ref_2_2 (const float *src);
        tensor_ref_2_2 (struct tensor_2_2 const & ten);
        tensor_ref_2_2 (tensor_ref_2_2 const & ten);
        tensor_ref_2 last (uint32_t i)
        {
            return &this->_data[i];
        }
    };
    struct tensor_2 : public diderot::tensor<float,2> {
        tensor_2 ()
            : diderot::tensor<float,2>()
        { }
        tensor_2 (std::initializer_list< float > const & il)
            : diderot::tensor<float,2>(il)
        { }
        tensor_2 (const float *src)
            : diderot::tensor<float,2>(src)
        { }
        tensor_2 (tensor_2 const & ten)
            : diderot::tensor<float,2>(ten._data)
        { }
        ~tensor_2 () { }
        tensor_2 & operator= (tensor_2 const & src);
        tensor_2 & operator= (tensor_ref_2 const & src);
        tensor_2 & operator= (std::initializer_list< float > const & il);
        tensor_2 & operator= (const float *src);
    };
    struct tensor_3 : public diderot::tensor<float,3> {
        tensor_3 ()
            : diderot::tensor<float,3>()
        { }
        tensor_3 (std::initializer_list< float > const & il)
            : diderot::tensor<float,3>(il)
        { }
        tensor_3 (const float *src)
            : diderot::tensor<float,3>(src)
        { }
        tensor_3 (tensor_3 const & ten)
            : diderot::tensor<float,3>(ten._data)
        { }
        ~tensor_3 () { }
        tensor_3 & operator= (tensor_3 const & src);
        tensor_3 & operator= (tensor_ref_3 const & src);
        tensor_3 & operator= (std::initializer_list< float > const & il);
        tensor_3 & operator= (const float *src);
    };
    struct tensor_2_2 : public diderot::tensor<float,4> {
        tensor_2_2 ()
            : diderot::tensor<float,4>()
        { }
        tensor_2_2 (std::initializer_list< float > const & il)
            : diderot::tensor<float,4>(il)
        { }
        tensor_2_2 (const float *src)
            : diderot::tensor<float,4>(src)
        { }
        tensor_2_2 (tensor_2_2 const & ten)
            : diderot::tensor<float,4>(ten._data)
        { }
        ~tensor_2_2 () { }
        tensor_2_2 & operator= (tensor_2_2 const & src);
        tensor_2_2 & operator= (tensor_ref_2_2 const & src);
        tensor_2_2 & operator= (std::initializer_list< float > const & il);
        tensor_2_2 & operator= (const float *src);
        tensor_ref_2 last (uint32_t i)
        {
            return &this->_data[i];
        }
    };
    inline tensor_ref_3::tensor_ref_3 (const float *src)
        : diderot::tensor_ref<float,3>(src)
    { }
    inline tensor_ref_3::tensor_ref_3 (struct tensor_3 const & ten)
        : diderot::tensor_ref<float,3>(ten._data)
    { }
    inline tensor_ref_3::tensor_ref_3 (tensor_ref_3 const & ten)
        : diderot::tensor_ref<float,3>(ten._data)
    { }
    inline tensor_ref_2::tensor_ref_2 (const float *src)
        : diderot::tensor_ref<float,2>(src)
    { }
    inline tensor_ref_2::tensor_ref_2 (struct tensor_2 const & ten)
        : diderot::tensor_ref<float,2>(ten._data)
    { }
    inline tensor_ref_2::tensor_ref_2 (tensor_ref_2 const & ten)
        : diderot::tensor_ref<float,2>(ten._data)
    { }
    inline tensor_ref_2_2::tensor_ref_2_2 (const float *src)
        : diderot::tensor_ref<float,4>(src)
    { }
    inline tensor_ref_2_2::tensor_ref_2_2 (struct tensor_2_2 const & ten)
        : diderot::tensor_ref<float,4>(ten._data)
    { }
    inline tensor_ref_2_2::tensor_ref_2_2 (tensor_ref_2_2 const & ten)
        : diderot::tensor_ref<float,4>(ten._data)
    { }
    inline tensor_2 & tensor_2::operator= (tensor_2 const & src)
    {
        this->copy(src._data);
        return *this;
    }
    inline tensor_2 & tensor_2::operator= (tensor_ref_2 const & src)
    {
        this->copy(src._data);
        return *this;
    }
    inline tensor_2 & tensor_2::operator= (std::initializer_list< float > const & il)
    {
        this->copy(il);
        return *this;
    }
    inline tensor_2 & tensor_2::operator= (const float *src)
    {
        this->copy(src);
        return *this;
    }
    inline tensor_3 & tensor_3::operator= (tensor_3 const & src)
    {
        this->copy(src._data);
        return *this;
    }
    inline tensor_3 & tensor_3::operator= (tensor_ref_3 const & src)
    {
        this->copy(src._data);
        return *this;
    }
    inline tensor_3 & tensor_3::operator= (std::initializer_list< float > const & il)
    {
        this->copy(il);
        return *this;
    }
    inline tensor_3 & tensor_3::operator= (const float *src)
    {
        this->copy(src);
        return *this;
    }
    inline tensor_2_2 & tensor_2_2::operator= (tensor_2_2 const & src)
    {
        this->copy(src._data);
        return *this;
    }
    inline tensor_2_2 & tensor_2_2::operator= (tensor_ref_2_2 const & src)
    {
        this->copy(src._data);
        return *this;
    }
    inline tensor_2_2 & tensor_2_2::operator= (std::initializer_list< float > const & il)
    {
        this->copy(il);
        return *this;
    }
    inline tensor_2_2 & tensor_2_2::operator= (const float *src)
    {
        this->copy(src);
        return *this;
    }
} // namespace Diderot
// ***** End synthesized types *****

/*---------- begin namespace-open.in ----------*/
namespace Diderot {

static std::string ProgramName = "maxgrad";

struct world;
struct sample_strand;
/*---------- end namespace-open.in ----------*/

/*---------- begin nrrd-save-helper.in ----------*/
/* helper function for saving output to nrrd file */
inline bool nrrd_save_helper (std::string const &file, Nrrd *nrrd)
{
    if (nrrdSave (file.c_str(), nrrd, nullptr)) {
        std::cerr << "Error saving \"" << file << "\":\n" << biffGetDone(NRRD) << std::endl;
        return true;
    }
    else {
        return false;
    }
}
/*---------- end nrrd-save-helper.in ----------*/

struct globals {
    diderot::image2d< float, float > gv_promote_img2;
    diderot::image2d< float, float > gv_promote_img1;
    diderot::image2d< float, float > gv_promote_img0;
    diderot::image2d< float, float > gv_promote_img;
    int32_t gv_outSize;
    int32_t gv_ex;
    int32_t gv_dx;
    ~globals ()
    {
        this->gv_promote_img2.free_data();
        this->gv_promote_img1.free_data();
        this->gv_promote_img0.free_data();
        this->gv_promote_img.free_data();
    }
};
struct sample_strand {
    tensor_2 sv_pos;
    tensor_3 sv_out;
    int32_t sv_i;
};
/*---------- begin seq-sarr.in ----------*/
// forward declarations of strand methods
#ifdef DIDEROT_HAS_START_METHOD
static diderot::strand_status sample_start (sample_strand *self);
#endif // DIDEROT_HAS_START_METHOD
static diderot::strand_status sample_update (globals *glob, sample_strand *self);
#ifdef DIDEROT_HAS_STABILIZE_METHOD
static void sample_stabilize (sample_strand *self);
#endif // DIDEROT_HAS_STABILIZE_METHOD

// strand_array for SEQUENTIAL/NO BSP/SINGLE STATE/DIRECT ACCESS
//
struct strand_array {
    typedef sample_strand strand_t;
    typedef uint32_t index_t;
    typedef index_t sid_t;              // strand ID (index into strand-state storage)

    uint8_t             *_status;       // the array of status information for the strands
    char                *_storage;      // points to array of sample_strand structs
    uint32_t            _nItems;        // number of items in the _storage and _status arrays
    uint32_t            _nStable;       // number of stable strands
    uint32_t            _nActive;       // number of active strands
    uint32_t		_nFresh;	// number of fresh strands (new strands from create_strands)

    strand_array () : _status(nullptr), _storage(nullptr), _nItems(0) { }
    ~strand_array ();

    uint32_t in_state_index () const { return 0; /* dummy */ }

    uint32_t num_active () const { return this->_nActive; }
    uint32_t num_stable () const { return this->_nStable; }
    uint32_t num_alive () const { return this->_nActive+this->_nStable; }

  // return the ID of a strand, which is the same as the ix index
    sid_t id (index_t ix) const
    {
        assert (ix < this->_nItems);
        return ix;
    }
  // return a pointer to the strand with the given ID
    sample_strand *id_to_strand (sid_t id) const
    {
        assert (id < this->_nItems);
        return reinterpret_cast<sample_strand *>(this->_storage + id * sizeof(sample_strand));
    }

  // return a strand's status
    diderot::strand_status status (index_t ix) const
    {
        assert (ix < this->_nItems);
        return static_cast<diderot::strand_status>(this->_status[ix]);
    }
  // return a pointer to the given strand
    sample_strand *strand (index_t ix) const
    {
        return this->id_to_strand(this->id(ix));
    }
  // return a pointer to the local state of strand ix
    sample_strand *local_state (index_t ix) const
    {
        return this->strand(ix);
    }
  // return a pointer to the local state of strand with the given ID
    sample_strand *id_to_local_state (sid_t id) const
    {
        return this->id_to_strand(id);
    }

  // allocate space for nItems
    bool alloc (uint32_t nItems)
    {
        this->_storage = static_cast<char *>(std::malloc (nItems * sizeof(sample_strand)));
        if (this->_storage == nullptr) {
            return true;
        }
        this->_status = static_cast<uint8_t *>(std::malloc (nItems * sizeof(uint8_t)));
        if (this->_status == nullptr) {
            std::free (this->_storage);
            return true;
        }
        this->_nItems = nItems;
        this->_nActive = 0;
        this->_nStable = 0;
        this->_nFresh = 0;
        return false;
    }

  // initialize the first nStrands locations as new active strands
    void create_strands (uint32_t nStrands)
    {
        assert (this->_nActive == 0);
        assert (this->_nItems == nStrands);
        for (index_t ix = 0;  ix < nStrands;  ix++) {
            this->_status[ix] = diderot::kActive;
            new (this->strand(ix)) sample_strand;
        }
        this->_nActive = nStrands;
        this->_nFresh = nStrands;
    }

  // swap in and out states (NOP for this version)
    void swap () { }

#ifdef DIDEROT_HAS_START_METHOD
  // invoke strand's start method
    diderot::strand_status strand_start (index_t ix)
    {
        return sample_start(this->strand(ix));
    }
#endif // DIDEROT_HAS_START_METHOD

  // invoke strand's update method
    diderot::strand_status strand_update (globals *glob, index_t ix)
    {
        return sample_update(glob, this->strand(ix));
    }

  // invoke strand's stabilize method
    index_t strand_stabilize (index_t ix)
    {
#ifdef DIDEROT_HAS_STABILIZE_METHOD
        sample_stabilize (this->strand(ix));
#endif // DIDEROT_HAS_STABILIZE_METHOD
        this->_status[ix] = diderot::kStable;
        this->_nActive--;
        this->_nStable++;
      // skip to next active strand
	do {
	    ix++;
        } while ((ix < this->_nItems) && (this->_status[ix] != diderot::kActive));
	return ix;
    }

  // mark the given strand as dead
    index_t kill (index_t ix)
    {
        this->_status[ix] = diderot::kDead;
        this->_nActive--;
      // skip to next active strand
	do {
	    ix++;
        } while ((ix < this->_nItems) && (this->_status[ix] != diderot::kActive));
	return ix;
    }

  // finish the local-phase of a superstep (NOP)
    void finish_step () { }

  // finish a kill_all operation (NOP)
    void finish_kill_all () { }

  // finish a stabilize_all operation (NOP)
    void finish_stabilize_all () { }

    index_t begin_alive () const
    {
        index_t ix = 0;
#ifdef DIDEROT_HAS_STRAND_DIE
        while ((ix < this->_nItems) && (this->_status[ix] == diderot::kDead)) {
            ix++;
        }
#endif
        return ix;
    }
    index_t end_alive () const { return this->_nItems; }
    index_t next_alive (index_t &ix) const
    {
        ix++;
#ifdef DIDEROT_HAS_STRAND_DIE
        while ((ix < this->_nItems) && (this->_status[ix] == diderot::kDead)) {
            ix++;
        }
#endif
        return ix;
    }

  // iterator over active strands
    index_t begin_active () const
    {
        index_t ix = 0;
        while ((ix < this->_nItems) && (this->_status[ix] != diderot::kActive)) {
            ix++;
        }
        return ix;
    }
    index_t end_active () const { return this->_nItems; }
    index_t next_active (index_t &ix) const
    {
	do {
	    ix++;
        } while ((ix < this->_nItems) && (this->_status[ix] != diderot::kActive));
        return ix;
    }

  // iterator over stable strands
    index_t begin_stable () const
    {
        index_t ix = 0;
        while ((ix < this->_nItems) && (this->_status[ix] != diderot::kStable)) {
            ix++;
        }
        return ix;
    }
    index_t end_stable () const { return this->_nItems; }
    index_t next_stable (index_t &ix) const
    {
	do {
	    ix++;
        } while ((ix < this->_nItems) && (this->_status[ix] != diderot::kStable));
        return ix;
    }

  // iterator over fresh strands; since the only new strands were created by create_strand
  // we iterate over all of them
    index_t begin_fresh () const { return 0; }
    index_t end_fresh () const { return this->_nFresh; }
    index_t next_fresh (index_t &ix) const { return ++ix; }

}; // struct strand_array

strand_array::~strand_array ()
{
  // run destructors to reclaim any dynamic memory attached to the strand state
    for (auto ix = this->begin_alive();  ix != this->end_alive();  ix = this->next_alive(ix)) {
        this->strand(ix)->~sample_strand();
    }
    if (this->_status != nullptr) std::free (this->_status);
    if (this->_storage != nullptr) std::free (this->_storage);
}
/*---------- end seq-sarr.in ----------*/

struct world : public diderot::world_base {
    strand_array _strands;
    globals *_globals;
    world ();
    ~world ();
    bool init ();
    bool alloc (int32_t base[1], uint32_t size[1]);
    bool create_strands ();
    uint32_t run (uint32_t max_nsteps);
    void swap_state ();
};
// ***** Begin synthesized operations *****

inline float vdot6 (vec6 u, vec6 v)
{
    vec6 w = u * v;
    return w[0] + w[1] + w[2] + w[3] + w[4] + w[5];
}
inline diderot::array< int, 2 > vtoi2 (vec2 src)
{
    diderot::array< int, 2 > res = {int32_t(src[0]),int32_t(src[1]),};
    return res;
}
inline vec2 vload2 (const float *vp)
{
    return __extension__ (vec2){vp[0], vp[1]};
}
inline vec2 vcons2 (float r0, float r1)
{
    return __extension__ (vec2){r0, r1};
}
inline vec3 vload3 (const float *vp)
{
    return __extension__ (vec3){vp[0], vp[1], vp[2], 0.0f};
}
template <typename TY>
inline bool inside2Ds3 (vec2 x0, diderot::image2d< float, TY > img)
{
    return 2 < x0[0] && x0[1] < img.size(1) - 3 && 2 < x0[1] && x0[0] < img.size(0) - 3;
}
inline vec3 vcons3 (float r0, float r1, float r2)
{
    return __extension__ (vec3){r0, r1, r2, 0.0f};
}
inline void vpack2 (tensor_2 &dst, vec2 v0)
{
    dst._data[0] = v0[0];
    dst._data[1] = v0[1];
}
inline void vpack3 (tensor_3 &dst, vec3 v0)
{
    dst._data[0] = v0[0];
    dst._data[1] = v0[1];
    dst._data[2] = v0[2];
}
template <typename TY>
inline tensor_ref_2_2 world2image (diderot::image2d< float, TY > const & img)
{
    return tensor_ref_2_2(img.world2image());
}
inline float vdot2 (vec2 u, vec2 v)
{
    vec2 w = u * v;
    return w[0] + w[1];
}
template <typename TY>
inline tensor_ref_2 translate (diderot::image2d< float, TY > const & img)
{
    return tensor_ref_2(img.translate());
}
inline vec6 vcons6 (float r0, float r1, float r2, float r3, float r4, float r5)
{
    return __extension__ (vec6){r0, r1, r2, r3, r4, r5, 0.0f, 0.0f};
}
float IfWrap (bool  e1, float e3, float e4)
	{ 
		 if(e1){return e3;}
		    else{return e4;}
	}
inline vec2 vfloor2 (vec2 v)
{
    return __extension__ (vec2){diderot::floor(v[0]), diderot::floor(v[1])};
}
// ***** End synthesized operations *****

static std::string OutputFile = "out.nrrd";
static void register_outputs (diderot::options *opts)
{
    opts->add("o,output", "specify output file", &OutputFile, true);
}
static bool init_globals (world *wrld)
{
    diderot::image2d< float, float > l_promote_img2_0;
    diderot::image2d< float, float > l_promote_img1_1;
    diderot::image2d< float, float > l_promote_img0_2;
    diderot::image2d< float, float > l_promote_img_3;
    globals *glob = wrld->_globals;
    if (l_promote_img2_0.load(wrld, "../../data/const7.nrrd")) {
        return true;
    }
    glob->gv_promote_img2 = l_promote_img2_0;
    if (l_promote_img1_1.load(wrld, "../../data/x7.nrrd")) {
        return true;
    }
    glob->gv_promote_img1 = l_promote_img1_1;
    if (l_promote_img0_2.load(wrld, "../../data/y7.nrrd")) {
        return true;
    }
    glob->gv_promote_img0 = l_promote_img0_2;
    if (l_promote_img_3.load(wrld, "../../data/xy7.nrrd")) {
        return true;
    }
    glob->gv_promote_img = l_promote_img_3;
    glob->gv_outSize = 5;
    glob->gv_ex = 2;
    glob->gv_dx = 1;
    return false;
}
static void sample_init (sample_strand *self, int32_t p_i_4)
{
    float l__t_5 = static_cast<float>(p_i_4);
    self->sv_pos[0] = l__t_5;
    self->sv_pos[1] = l__t_5;
    self->sv_out[0] = -0.77e2f;
    self->sv_out[1] = -0.77e2f;
    self->sv_out[2] = -0.77e2f;
    self->sv_i = p_i_4;
}
static diderot::strand_status sample_update (globals *glob, sample_strand *self)
{
    vec2 v_8;
    vec3 v_151;
    if (self->sv_i == 0) {
        v_8 = vcons2(0.1e0f, 0.1e0f);
    }
    else {
        vec2 v_9;
        if (self->sv_i == 1) {
            v_9 = vcons2(0.2e0f, 0.2e0f);
        }
        else {
            vec2 v_10;
            if (self->sv_i == 2) {
                v_10 = vcons2(-0.2e0f, -0.2e0f);
            }
            else {
                vec2 v_11;
                if (self->sv_i == 3) {
                    v_11 = vcons2(-0.4e0f, -0.4e0f);
                }
                else {
                    vec2 v_12;
                    if (self->sv_i == 4) {
                        v_12 = vcons2(0.4e0f, 0.4e0f);
                    }
                    else {
                        v_12 = vload2(tensor_ref_2(self->sv_pos).addr(0));
                    }
                    v_11 = v_12;
                }
                v_10 = v_11;
            }
            v_9 = v_10;
        }
        v_8 = v_9;
    }
    if (glob->gv_ex == 1) {
        vec3 v_150;
        tensor_ref_2_2 l_Mtransform_13 = world2image(glob->gv_promote_img2);
        vec2 v_14 = vcons2(vdot2(vload2(l_Mtransform_13.last(0).addr(0)), v_8),
            vdot2(vload2(l_Mtransform_13.last(2).addr(0)), v_8)) + vload2(translate(glob->gv_promote_img2).addr(0));
        tensor_ref_2_2 l_Mtransform_15 = world2image(glob->gv_promote_img1);
        vec2 v_16 = vcons2(vdot2(vload2(l_Mtransform_15.last(0).addr(0)), v_8),
            vdot2(vload2(l_Mtransform_15.last(2).addr(0)), v_8)) + vload2(translate(glob->gv_promote_img1).addr(0));
        vec2 v_17 = v_14;
        vec2 v_18 = v_16;
        if (inside2Ds3(v_14, glob->gv_promote_img2) && inside2Ds3(v_16, glob->gv_promote_img1)) {
            vec3 v_70;
            vec3 v_149;
            if (glob->gv_dx == 0) {
                vec2 v_19 = vfloor2(v_17);
                vec2 v_20 = v_17 - v_19;
                diderot::array< int32_t, 2 > l_n_21 = vtoi2(v_19);
                int32_t l_idx_22 = l_n_21[0] + -2;
                int32_t l_idx_23 = l_n_21[1] + -2;
                int32_t l_mulRes_24 = 70 * l_idx_23;
                int32_t l_addRes_25 = l_idx_22 + 1;
                int32_t l_addRes_26 = l_idx_22 + 2;
                int32_t l_addRes_27 = l_idx_22 + 3;
                int32_t l_addRes_28 = l_idx_22 + 4;
                int32_t l_addRes_29 = l_idx_22 + 5;
                int32_t l_mulRes_30 = 70 * (l_idx_23 + 1);
                int32_t l_mulRes_31 = 70 * (l_idx_23 + 2);
                int32_t l_mulRes_32 = 70 * (l_idx_23 + 3);
                int32_t l_mulRes_33 = 70 * (l_idx_23 + 4);
                int32_t l_mulRes_34 = 70 * (l_idx_23 + 5);
                float l_vY__35 = v_20[1];
                vec6 v_36 = vcons6(l_vY__35 + 0.2e1f, l_vY__35 + 0.1e1f, l_vY__35, l_vY__35 - 0.1e1f,
                    l_vY__35 - 0.2e1f, l_vY__35 - 0.3e1f);
                vec6 v_37 = vcons6(0.961875e1f, 0.1875e-1f, 0.8625e0f, 0.8625e0f, 0.1875e-1f, 0.961875e1f);
                vec6 v_38 = vcons6(-0.23625e2f, 0.4375e1f, 0.0f, 0.0f, -0.4375e1f, 0.23625e2f);
                vec6 v_39 = vcons6(0.2334375e2f, -0.1065625e2f, -0.14375e1f, -0.14375e1f, -0.1065625e2f, 0.2334375e2f);
                vec6 v_40 = vcons6(-0.12e2f, 0.10e2f, 0.0f, 0.0f, -0.10e2f, 0.12e2f);
                vec6 v_41 = vcons6(0.340625e1f, -0.459375e1f, 0.11875e1f, 0.11875e1f, -0.459375e1f, 0.340625e1f);
                vec6 v_42 = vcons6(-0.508333333333e0f, 0.104166666667e1f, -0.583333333333e0f, 0.583333333333e0f,
                    -0.104166666667e1f, 0.508333333333e0f);
                vec6 v_43 = vcons6(0.3125e-1f, -0.9375e-1f, 0.625e-1f, 0.625e-1f, -0.9375e-1f, 0.3125e-1f);
                float l_vX__44 = v_20[0];
                vec6 v_45 = vcons6(l_vX__44 + 0.2e1f, l_vX__44 + 0.1e1f, l_vX__44, l_vX__44 - 0.1e1f,
                    l_vX__44 - 0.2e1f, l_vX__44 - 0.3e1f);
                vec6 v_46 = v_37 + v_45 * (v_38 + v_45 * (v_39 + v_45 * (v_40 + v_45 * (v_41 + v_45 * (v_42 + v_45 * v_43)))));
                float l__t_47 = vdot6(
                    v_37 + v_36 * (v_38 + v_36 * (v_39 + v_36 * (v_40 + v_36 * (v_41 + v_36 * (v_42 + v_36 * v_43))))),
                    vcons6(
                        vdot6(v_46,
                            vcons6(glob->gv_promote_img2[l_idx_22 + l_mulRes_24],
                                glob->gv_promote_img2[l_addRes_25 + l_mulRes_24],
                                glob->gv_promote_img2[l_addRes_26 + l_mulRes_24],
                                glob->gv_promote_img2[l_addRes_27 + l_mulRes_24],
                                glob->gv_promote_img2[l_addRes_28 + l_mulRes_24],
                                glob->gv_promote_img2[l_addRes_29 + l_mulRes_24])),
                        vdot6(v_46,
                            vcons6(glob->gv_promote_img2[l_idx_22 + l_mulRes_30],
                                glob->gv_promote_img2[l_addRes_25 + l_mulRes_30],
                                glob->gv_promote_img2[l_addRes_26 + l_mulRes_30],
                                glob->gv_promote_img2[l_addRes_27 + l_mulRes_30],
                                glob->gv_promote_img2[l_addRes_28 + l_mulRes_30],
                                glob->gv_promote_img2[l_addRes_29 + l_mulRes_30])),
                        vdot6(v_46,
                            vcons6(glob->gv_promote_img2[l_idx_22 + l_mulRes_31],
                                glob->gv_promote_img2[l_addRes_25 + l_mulRes_31],
                                glob->gv_promote_img2[l_addRes_26 + l_mulRes_31],
                                glob->gv_promote_img2[l_addRes_27 + l_mulRes_31],
                                glob->gv_promote_img2[l_addRes_28 + l_mulRes_31],
                                glob->gv_promote_img2[l_addRes_29 + l_mulRes_31])),
                        vdot6(v_46,
                            vcons6(glob->gv_promote_img2[l_idx_22 + l_mulRes_32],
                                glob->gv_promote_img2[l_addRes_25 + l_mulRes_32],
                                glob->gv_promote_img2[l_addRes_26 + l_mulRes_32],
                                glob->gv_promote_img2[l_addRes_27 + l_mulRes_32],
                                glob->gv_promote_img2[l_addRes_28 + l_mulRes_32],
                                glob->gv_promote_img2[l_addRes_29 + l_mulRes_32])),
                        vdot6(v_46,
                            vcons6(glob->gv_promote_img2[l_idx_22 + l_mulRes_33],
                                glob->gv_promote_img2[l_addRes_25 + l_mulRes_33],
                                glob->gv_promote_img2[l_addRes_26 + l_mulRes_33],
                                glob->gv_promote_img2[l_addRes_27 + l_mulRes_33],
                                glob->gv_promote_img2[l_addRes_28 + l_mulRes_33],
                                glob->gv_promote_img2[l_addRes_29 + l_mulRes_33])),
                        vdot6(v_46,
                            vcons6(glob->gv_promote_img2[l_idx_22 + l_mulRes_34],
                                glob->gv_promote_img2[l_addRes_25 + l_mulRes_34],
                                glob->gv_promote_img2[l_addRes_26 + l_mulRes_34],
                                glob->gv_promote_img2[l_addRes_27 + l_mulRes_34],
                                glob->gv_promote_img2[l_addRes_28 + l_mulRes_34],
                                glob->gv_promote_img2[l_addRes_29 + l_mulRes_34]))));
                vec2 v_48 = vfloor2(v_18);
                vec2 v_49 = v_18 - v_48;
                diderot::array< int32_t, 2 > l_n_50 = vtoi2(v_48);
                int32_t l_idx_51 = l_n_50[0] + -2;
                int32_t l_idx_52 = l_n_50[1] + -2;
                int32_t l_mulRes_53 = 70 * l_idx_52;
                int32_t l_addRes_54 = l_idx_51 + 1;
                int32_t l_addRes_55 = l_idx_51 + 2;
                int32_t l_addRes_56 = l_idx_51 + 3;
                int32_t l_addRes_57 = l_idx_51 + 4;
                int32_t l_addRes_58 = l_idx_51 + 5;
                int32_t l_mulRes_59 = 70 * (l_idx_52 + 1);
                int32_t l_mulRes_60 = 70 * (l_idx_52 + 2);
                int32_t l_mulRes_61 = 70 * (l_idx_52 + 3);
                int32_t l_mulRes_62 = 70 * (l_idx_52 + 4);
                int32_t l_mulRes_63 = 70 * (l_idx_52 + 5);
                float l_vY__64 = v_49[1];
                vec6 v_65 = vcons6(l_vY__64 + 0.2e1f, l_vY__64 + 0.1e1f, l_vY__64, l_vY__64 - 0.1e1f,
                    l_vY__64 - 0.2e1f, l_vY__64 - 0.3e1f);
                float l_vX__66 = v_49[0];
                vec6 v_67 = vcons6(l_vX__66 + 0.2e1f, l_vX__66 + 0.1e1f, l_vX__66, l_vX__66 - 0.1e1f,
                    l_vX__66 - 0.2e1f, l_vX__66 - 0.3e1f);
                vec6 v_68 = v_37 + v_67 * (v_38 + v_67 * (v_39 + v_67 * (v_40 + v_67 * (v_41 + v_67 * (v_42 + v_67 * v_43)))));
                float l__t_69 = vdot6(
                    v_37 + v_65 * (v_38 + v_65 * (v_39 + v_65 * (v_40 + v_65 * (v_41 + v_65 * (v_42 + v_65 * v_43))))),
                    vcons6(
                        vdot6(v_68,
                            vcons6(glob->gv_promote_img1[l_idx_51 + l_mulRes_53],
                                glob->gv_promote_img1[l_addRes_54 + l_mulRes_53],
                                glob->gv_promote_img1[l_addRes_55 + l_mulRes_53],
                                glob->gv_promote_img1[l_addRes_56 + l_mulRes_53],
                                glob->gv_promote_img1[l_addRes_57 + l_mulRes_53],
                                glob->gv_promote_img1[l_addRes_58 + l_mulRes_53])),
                        vdot6(v_68,
                            vcons6(glob->gv_promote_img1[l_idx_51 + l_mulRes_59],
                                glob->gv_promote_img1[l_addRes_54 + l_mulRes_59],
                                glob->gv_promote_img1[l_addRes_55 + l_mulRes_59],
                                glob->gv_promote_img1[l_addRes_56 + l_mulRes_59],
                                glob->gv_promote_img1[l_addRes_57 + l_mulRes_59],
                                glob->gv_promote_img1[l_addRes_58 + l_mulRes_59])),
                        vdot6(v_68,
                            vcons6(glob->gv_promote_img1[l_idx_51 + l_mulRes_60],
                                glob->gv_promote_img1[l_addRes_54 + l_mulRes_60],
                                glob->gv_promote_img1[l_addRes_55 + l_mulRes_60],
                                glob->gv_promote_img1[l_addRes_56 + l_mulRes_60],
                                glob->gv_promote_img1[l_addRes_57 + l_mulRes_60],
                                glob->gv_promote_img1[l_addRes_58 + l_mulRes_60])),
                        vdot6(v_68,
                            vcons6(glob->gv_promote_img1[l_idx_51 + l_mulRes_61],
                                glob->gv_promote_img1[l_addRes_54 + l_mulRes_61],
                                glob->gv_promote_img1[l_addRes_55 + l_mulRes_61],
                                glob->gv_promote_img1[l_addRes_56 + l_mulRes_61],
                                glob->gv_promote_img1[l_addRes_57 + l_mulRes_61],
                                glob->gv_promote_img1[l_addRes_58 + l_mulRes_61])),
                        vdot6(v_68,
                            vcons6(glob->gv_promote_img1[l_idx_51 + l_mulRes_62],
                                glob->gv_promote_img1[l_addRes_54 + l_mulRes_62],
                                glob->gv_promote_img1[l_addRes_55 + l_mulRes_62],
                                glob->gv_promote_img1[l_addRes_56 + l_mulRes_62],
                                glob->gv_promote_img1[l_addRes_57 + l_mulRes_62],
                                glob->gv_promote_img1[l_addRes_58 + l_mulRes_62])),
                        vdot6(v_68,
                            vcons6(glob->gv_promote_img1[l_idx_51 + l_mulRes_63],
                                glob->gv_promote_img1[l_addRes_54 + l_mulRes_63],
                                glob->gv_promote_img1[l_addRes_55 + l_mulRes_63],
                                glob->gv_promote_img1[l_addRes_56 + l_mulRes_63],
                                glob->gv_promote_img1[l_addRes_57 + l_mulRes_63],
                                glob->gv_promote_img1[l_addRes_58 + l_mulRes_63]))));
                v_70 = vcons3(l__t_47, l__t_69, std::max(l__t_47, l__t_69));
            }
            else {
                v_70 = vload3(tensor_ref_3(self->sv_out).addr(0));
            }
            if (glob->gv_dx == 1) {
                vec2 v_71 = vfloor2(v_17);
                vec2 v_72 = v_17 - v_71;
                diderot::array< int32_t, 2 > l_n_73 = vtoi2(v_71);
                int32_t l_idx_74 = l_n_73[0] + -2;
                int32_t l_idx_75 = l_n_73[1] + -2;
                int32_t l_mulRes_76 = 70 * l_idx_75;
                int32_t l_addRes_77 = l_idx_74 + 1;
                int32_t l_addRes_78 = l_idx_74 + 2;
                int32_t l_addRes_79 = l_idx_74 + 3;
                int32_t l_addRes_80 = l_idx_74 + 4;
                int32_t l_addRes_81 = l_idx_74 + 5;
                vec6 v_82 = vcons6(glob->gv_promote_img2[l_idx_74 + l_mulRes_76],
                    glob->gv_promote_img2[l_addRes_77 + l_mulRes_76], glob->gv_promote_img2[l_addRes_78 + l_mulRes_76],
                    glob->gv_promote_img2[l_addRes_79 + l_mulRes_76], glob->gv_promote_img2[l_addRes_80 + l_mulRes_76],
                    glob->gv_promote_img2[l_addRes_81 + l_mulRes_76]);
                int32_t l_mulRes_83 = 70 * (l_idx_75 + 1);
                vec6 v_84 = vcons6(glob->gv_promote_img2[l_idx_74 + l_mulRes_83],
                    glob->gv_promote_img2[l_addRes_77 + l_mulRes_83], glob->gv_promote_img2[l_addRes_78 + l_mulRes_83],
                    glob->gv_promote_img2[l_addRes_79 + l_mulRes_83], glob->gv_promote_img2[l_addRes_80 + l_mulRes_83],
                    glob->gv_promote_img2[l_addRes_81 + l_mulRes_83]);
                int32_t l_mulRes_85 = 70 * (l_idx_75 + 2);
                vec6 v_86 = vcons6(glob->gv_promote_img2[l_idx_74 + l_mulRes_85],
                    glob->gv_promote_img2[l_addRes_77 + l_mulRes_85], glob->gv_promote_img2[l_addRes_78 + l_mulRes_85],
                    glob->gv_promote_img2[l_addRes_79 + l_mulRes_85], glob->gv_promote_img2[l_addRes_80 + l_mulRes_85],
                    glob->gv_promote_img2[l_addRes_81 + l_mulRes_85]);
                int32_t l_mulRes_87 = 70 * (l_idx_75 + 3);
                vec6 v_88 = vcons6(glob->gv_promote_img2[l_idx_74 + l_mulRes_87],
                    glob->gv_promote_img2[l_addRes_77 + l_mulRes_87], glob->gv_promote_img2[l_addRes_78 + l_mulRes_87],
                    glob->gv_promote_img2[l_addRes_79 + l_mulRes_87], glob->gv_promote_img2[l_addRes_80 + l_mulRes_87],
                    glob->gv_promote_img2[l_addRes_81 + l_mulRes_87]);
                int32_t l_mulRes_89 = 70 * (l_idx_75 + 4);
                vec6 v_90 = vcons6(glob->gv_promote_img2[l_idx_74 + l_mulRes_89],
                    glob->gv_promote_img2[l_addRes_77 + l_mulRes_89], glob->gv_promote_img2[l_addRes_78 + l_mulRes_89],
                    glob->gv_promote_img2[l_addRes_79 + l_mulRes_89], glob->gv_promote_img2[l_addRes_80 + l_mulRes_89],
                    glob->gv_promote_img2[l_addRes_81 + l_mulRes_89]);
                int32_t l_mulRes_91 = 70 * (l_idx_75 + 5);
                vec6 v_92 = vcons6(glob->gv_promote_img2[l_idx_74 + l_mulRes_91],
                    glob->gv_promote_img2[l_addRes_77 + l_mulRes_91], glob->gv_promote_img2[l_addRes_78 + l_mulRes_91],
                    glob->gv_promote_img2[l_addRes_79 + l_mulRes_91], glob->gv_promote_img2[l_addRes_80 + l_mulRes_91],
                    glob->gv_promote_img2[l_addRes_81 + l_mulRes_91]);
                float l_vY__93 = v_72[1];
                vec6 v_94 = vcons6(l_vY__93 + 0.2e1f, l_vY__93 + 0.1e1f, l_vY__93, l_vY__93 - 0.1e1f,
                    l_vY__93 - 0.2e1f, l_vY__93 - 0.3e1f);
                vec6 v_95 = vcons6(0.961875e1f, 0.1875e-1f, 0.8625e0f, 0.8625e0f, 0.1875e-1f, 0.961875e1f);
                vec6 v_96 = vcons6(-0.23625e2f, 0.4375e1f, 0.0f, 0.0f, -0.4375e1f, 0.23625e2f);
                vec6 v_97 = vcons6(0.2334375e2f, -0.1065625e2f, -0.14375e1f, -0.14375e1f, -0.1065625e2f, 0.2334375e2f);
                vec6 v_98 = vcons6(-0.12e2f, 0.10e2f, 0.0f, 0.0f, -0.10e2f, 0.12e2f);
                vec6 v_99 = vcons6(0.340625e1f, -0.459375e1f, 0.11875e1f, 0.11875e1f, -0.459375e1f, 0.340625e1f);
                vec6 v_100 = vcons6(-0.508333333333e0f, 0.104166666667e1f, -0.583333333333e0f, 0.583333333333e0f,
                    -0.104166666667e1f, 0.508333333333e0f);
                vec6 v_101 = vcons6(0.3125e-1f, -0.9375e-1f, 0.625e-1f, 0.625e-1f, -0.9375e-1f, 0.3125e-1f);
                vec6 v_102 = v_95 + v_94 * (v_96 + v_94 * (v_97 + v_94 * (v_98 + v_94 * (v_99 + v_94 * (v_100 + v_94 * v_101)))));
                float l_vX__103 = v_72[0];
                vec6 v_104 = vcons6(l_vX__103 + 0.2e1f, l_vX__103 + 0.1e1f, l_vX__103, l_vX__103 - 0.1e1f,
                    l_vX__103 - 0.2e1f, l_vX__103 - 0.3e1f);
                vec6 v_105 = v_95 + v_104 * (v_96 + v_104 * (v_97 + v_104 * (v_98 + v_104 * (v_99 + v_104 * (v_100 + v_104 * v_101)))));
                vec6 v_106 = vcons6(vdot6(v_105, v_82), vdot6(v_105, v_84), vdot6(v_105, v_86), vdot6(v_105, v_88),
                    vdot6(v_105, v_90), vdot6(v_105, v_92));
                float l_probe_l_5_107 = vdot6(v_102, v_106);
                vec2 v_108 = vfloor2(v_18);
                vec2 v_109 = v_18 - v_108;
                diderot::array< int32_t, 2 > l_n_110 = vtoi2(v_108);
                int32_t l_idx_111 = l_n_110[0] + -2;
                int32_t l_idx_112 = l_n_110[1] + -2;
                int32_t l_mulRes_113 = 70 * l_idx_112;
                int32_t l_addRes_114 = l_idx_111 + 1;
                int32_t l_addRes_115 = l_idx_111 + 2;
                int32_t l_addRes_116 = l_idx_111 + 3;
                int32_t l_addRes_117 = l_idx_111 + 4;
                int32_t l_addRes_118 = l_idx_111 + 5;
                vec6 v_119 = vcons6(glob->gv_promote_img1[l_idx_111 + l_mulRes_113],
                    glob->gv_promote_img1[l_addRes_114 + l_mulRes_113],
                    glob->gv_promote_img1[l_addRes_115 + l_mulRes_113],
                    glob->gv_promote_img1[l_addRes_116 + l_mulRes_113],
                    glob->gv_promote_img1[l_addRes_117 + l_mulRes_113],
                    glob->gv_promote_img1[l_addRes_118 + l_mulRes_113]);
                int32_t l_mulRes_120 = 70 * (l_idx_112 + 1);
                vec6 v_121 = vcons6(glob->gv_promote_img1[l_idx_111 + l_mulRes_120],
                    glob->gv_promote_img1[l_addRes_114 + l_mulRes_120],
                    glob->gv_promote_img1[l_addRes_115 + l_mulRes_120],
                    glob->gv_promote_img1[l_addRes_116 + l_mulRes_120],
                    glob->gv_promote_img1[l_addRes_117 + l_mulRes_120],
                    glob->gv_promote_img1[l_addRes_118 + l_mulRes_120]);
                int32_t l_mulRes_122 = 70 * (l_idx_112 + 2);
                vec6 v_123 = vcons6(glob->gv_promote_img1[l_idx_111 + l_mulRes_122],
                    glob->gv_promote_img1[l_addRes_114 + l_mulRes_122],
                    glob->gv_promote_img1[l_addRes_115 + l_mulRes_122],
                    glob->gv_promote_img1[l_addRes_116 + l_mulRes_122],
                    glob->gv_promote_img1[l_addRes_117 + l_mulRes_122],
                    glob->gv_promote_img1[l_addRes_118 + l_mulRes_122]);
                int32_t l_mulRes_124 = 70 * (l_idx_112 + 3);
                vec6 v_125 = vcons6(glob->gv_promote_img1[l_idx_111 + l_mulRes_124],
                    glob->gv_promote_img1[l_addRes_114 + l_mulRes_124],
                    glob->gv_promote_img1[l_addRes_115 + l_mulRes_124],
                    glob->gv_promote_img1[l_addRes_116 + l_mulRes_124],
                    glob->gv_promote_img1[l_addRes_117 + l_mulRes_124],
                    glob->gv_promote_img1[l_addRes_118 + l_mulRes_124]);
                int32_t l_mulRes_126 = 70 * (l_idx_112 + 4);
                vec6 v_127 = vcons6(glob->gv_promote_img1[l_idx_111 + l_mulRes_126],
                    glob->gv_promote_img1[l_addRes_114 + l_mulRes_126],
                    glob->gv_promote_img1[l_addRes_115 + l_mulRes_126],
                    glob->gv_promote_img1[l_addRes_116 + l_mulRes_126],
                    glob->gv_promote_img1[l_addRes_117 + l_mulRes_126],
                    glob->gv_promote_img1[l_addRes_118 + l_mulRes_126]);
                int32_t l_mulRes_128 = 70 * (l_idx_112 + 5);
                vec6 v_129 = vcons6(glob->gv_promote_img1[l_idx_111 + l_mulRes_128],
                    glob->gv_promote_img1[l_addRes_114 + l_mulRes_128],
                    glob->gv_promote_img1[l_addRes_115 + l_mulRes_128],
                    glob->gv_promote_img1[l_addRes_116 + l_mulRes_128],
                    glob->gv_promote_img1[l_addRes_117 + l_mulRes_128],
                    glob->gv_promote_img1[l_addRes_118 + l_mulRes_128]);
                float l_vY__130 = v_109[1];
                vec6 v_131 = vcons6(l_vY__130 + 0.2e1f, l_vY__130 + 0.1e1f, l_vY__130, l_vY__130 - 0.1e1f,
                    l_vY__130 - 0.2e1f, l_vY__130 - 0.3e1f);
                vec6 v_132 = v_95 + v_131 * (v_96 + v_131 * (v_97 + v_131 * (v_98 + v_131 * (v_99 + v_131 * (v_100 + v_131 * v_101)))));
                float l_vX__133 = v_109[0];
                vec6 v_134 = vcons6(l_vX__133 + 0.2e1f, l_vX__133 + 0.1e1f, l_vX__133, l_vX__133 - 0.1e1f,
                    l_vX__133 - 0.2e1f, l_vX__133 - 0.3e1f);
                vec6 v_135 = v_95 + v_134 * (v_96 + v_134 * (v_97 + v_134 * (v_98 + v_134 * (v_99 + v_134 * (v_100 + v_134 * v_101)))));
                vec6 v_136 = vcons6(vdot6(v_135, v_119), vdot6(v_135, v_121), vdot6(v_135, v_123), vdot6(v_135, v_125),
                    vdot6(v_135, v_127), vdot6(v_135, v_129));
                float l_probe_l_6_137 = vdot6(v_132, v_136);
                vec6 v_138 = vcons6(0.466875e2f, -0.213125e2f, -0.2875e1f, -0.2875e1f, -0.213125e2f, 0.466875e2f);
                vec6 v_139 = vcons6(-0.36e2f, 0.30e2f, 0.0f, 0.0f, -0.30e2f, 0.36e2f);
                vec6 v_140 = vcons6(0.13625e2f, -0.18375e2f, 0.475e1f, 0.475e1f, -0.18375e2f, 0.13625e2f);
                vec6 v_141 = vcons6(-0.254166666667e1f, 0.520833333333e1f, -0.291666666667e1f, 0.291666666667e1f,
                    -0.520833333333e1f, 0.254166666667e1f);
                vec6 v_142 = vcons6(0.1875e0f, -0.5625e0f, 0.375e0f, 0.375e0f, -0.5625e0f, 0.1875e0f);
                vec6 v_143 = v_96 + v_104 * (v_138 + v_104 * (v_139 + v_104 * (v_140 + v_104 * (v_141 + v_104 * v_142))));
                vec2 v_144 = vcons2(
                    vdot6(v_102,
                        vcons6(vdot6(v_143, v_82), vdot6(v_143, v_84), vdot6(v_143, v_86), vdot6(v_143, v_88),
                            vdot6(v_143, v_90), vdot6(v_143, v_92))),
                    vdot6(v_96 + v_94 * (v_138 + v_94 * (v_139 + v_94 * (v_140 + v_94 * (v_141 + v_94 * v_142)))),
                        v_106));
                vec6 v_145 = v_96 + v_134 * (v_138 + v_134 * (v_139 + v_134 * (v_140 + v_134 * (v_141 + v_134 * v_142))));
                vec2 v_146 = vcons2(
                    vdot6(v_132,
                        vcons6(vdot6(v_145, v_119), vdot6(v_145, v_121), vdot6(v_145, v_123), vdot6(v_145, v_125),
                            vdot6(v_145, v_127), vdot6(v_145, v_129))),
                    vdot6(v_96 + v_131 * (v_138 + v_131 * (v_139 + v_131 * (v_140 + v_131 * (v_141 + v_131 * v_142)))),
                        v_136));
                bool l_r_147 = l_probe_l_5_107 > l_probe_l_6_137;
                vec2 v_148 = vcons2(
                    IfWrap(l_r_147, vdot2(v_144, vcons2(l_Mtransform_13[0], l_Mtransform_13[2])),
                        vdot2(v_146, vcons2(l_Mtransform_15[0], l_Mtransform_15[2]))),
                    IfWrap(l_r_147, vdot2(v_144, vcons2(l_Mtransform_13[1], l_Mtransform_13[3])),
                        vdot2(v_146, vcons2(l_Mtransform_15[1], l_Mtransform_15[3]))));
                v_149 = vcons3(v_148[0], v_148[1], std::max(l_probe_l_5_107, l_probe_l_6_137));
            }
            else {
                v_149 = v_70;
            }
            v_150 = v_149;
        }
        else {
            v_150 = vload3(tensor_ref_3(self->sv_out).addr(0));
        }
        v_151 = v_150;
    }
    else {
        vec3 v_290;
        if (glob->gv_ex == 2) {
            vec3 v_289;
            tensor_ref_2_2 l_Mtransform_152 = world2image(glob->gv_promote_img0);
            vec2 v_153 = vcons2(vdot2(vload2(l_Mtransform_152.last(0).addr(0)), v_8),
                vdot2(vload2(l_Mtransform_152.last(2).addr(0)), v_8)) + vload2(
                translate(glob->gv_promote_img0).addr(0));
            tensor_ref_2_2 l_Mtransform_154 = world2image(glob->gv_promote_img);
            vec2 v_155 = vcons2(vdot2(vload2(l_Mtransform_154.last(0).addr(0)), v_8),
                vdot2(vload2(l_Mtransform_154.last(2).addr(0)), v_8)) + vload2(translate(glob->gv_promote_img).addr(0));
            vec2 v_156 = v_153;
            vec2 v_157 = v_155;
            if (inside2Ds3(v_153, glob->gv_promote_img0) && inside2Ds3(v_155, glob->gv_promote_img)) {
                vec3 v_209;
                vec3 v_288;
                if (glob->gv_dx == 0) {
                    vec2 v_158 = vfloor2(v_156);
                    vec2 v_159 = v_156 - v_158;
                    diderot::array< int32_t, 2 > l_n_160 = vtoi2(v_158);
                    int32_t l_idx_161 = l_n_160[0] + -2;
                    int32_t l_idx_162 = l_n_160[1] + -2;
                    int32_t l_mulRes_163 = 70 * l_idx_162;
                    int32_t l_addRes_164 = l_idx_161 + 1;
                    int32_t l_addRes_165 = l_idx_161 + 2;
                    int32_t l_addRes_166 = l_idx_161 + 3;
                    int32_t l_addRes_167 = l_idx_161 + 4;
                    int32_t l_addRes_168 = l_idx_161 + 5;
                    int32_t l_mulRes_169 = 70 * (l_idx_162 + 1);
                    int32_t l_mulRes_170 = 70 * (l_idx_162 + 2);
                    int32_t l_mulRes_171 = 70 * (l_idx_162 + 3);
                    int32_t l_mulRes_172 = 70 * (l_idx_162 + 4);
                    int32_t l_mulRes_173 = 70 * (l_idx_162 + 5);
                    float l_vY__174 = v_159[1];
                    vec6 v_175 = vcons6(l_vY__174 + 0.2e1f, l_vY__174 + 0.1e1f, l_vY__174, l_vY__174 - 0.1e1f,
                        l_vY__174 - 0.2e1f, l_vY__174 - 0.3e1f);
                    vec6 v_176 = vcons6(0.961875e1f, 0.1875e-1f, 0.8625e0f, 0.8625e0f, 0.1875e-1f, 0.961875e1f);
                    vec6 v_177 = vcons6(-0.23625e2f, 0.4375e1f, 0.0f, 0.0f, -0.4375e1f, 0.23625e2f);
                    vec6 v_178 = vcons6(0.2334375e2f, -0.1065625e2f, -0.14375e1f, -0.14375e1f, -0.1065625e2f,
                        0.2334375e2f);
                    vec6 v_179 = vcons6(-0.12e2f, 0.10e2f, 0.0f, 0.0f, -0.10e2f, 0.12e2f);
                    vec6 v_180 = vcons6(0.340625e1f, -0.459375e1f, 0.11875e1f, 0.11875e1f, -0.459375e1f, 0.340625e1f);
                    vec6 v_181 = vcons6(-0.508333333333e0f, 0.104166666667e1f, -0.583333333333e0f, 0.583333333333e0f,
                        -0.104166666667e1f, 0.508333333333e0f);
                    vec6 v_182 = vcons6(0.3125e-1f, -0.9375e-1f, 0.625e-1f, 0.625e-1f, -0.9375e-1f, 0.3125e-1f);
                    float l_vX__183 = v_159[0];
                    vec6 v_184 = vcons6(l_vX__183 + 0.2e1f, l_vX__183 + 0.1e1f, l_vX__183, l_vX__183 - 0.1e1f,
                        l_vX__183 - 0.2e1f, l_vX__183 - 0.3e1f);
                    vec6 v_185 = v_176 + v_184 * (v_177 + v_184 * (v_178 + v_184 * (v_179 + v_184 * (v_180 + v_184 * (v_181 + v_184 * v_182)))));
                    float l__t_186 = vdot6(
                        v_176 + v_175 * (v_177 + v_175 * (v_178 + v_175 * (v_179 + v_175 * (v_180 + v_175 * (v_181 + v_175 * v_182))))),
                        vcons6(
                            vdot6(v_185,
                                vcons6(glob->gv_promote_img0[l_idx_161 + l_mulRes_163],
                                    glob->gv_promote_img0[l_addRes_164 + l_mulRes_163],
                                    glob->gv_promote_img0[l_addRes_165 + l_mulRes_163],
                                    glob->gv_promote_img0[l_addRes_166 + l_mulRes_163],
                                    glob->gv_promote_img0[l_addRes_167 + l_mulRes_163],
                                    glob->gv_promote_img0[l_addRes_168 + l_mulRes_163])),
                            vdot6(v_185,
                                vcons6(glob->gv_promote_img0[l_idx_161 + l_mulRes_169],
                                    glob->gv_promote_img0[l_addRes_164 + l_mulRes_169],
                                    glob->gv_promote_img0[l_addRes_165 + l_mulRes_169],
                                    glob->gv_promote_img0[l_addRes_166 + l_mulRes_169],
                                    glob->gv_promote_img0[l_addRes_167 + l_mulRes_169],
                                    glob->gv_promote_img0[l_addRes_168 + l_mulRes_169])),
                            vdot6(v_185,
                                vcons6(glob->gv_promote_img0[l_idx_161 + l_mulRes_170],
                                    glob->gv_promote_img0[l_addRes_164 + l_mulRes_170],
                                    glob->gv_promote_img0[l_addRes_165 + l_mulRes_170],
                                    glob->gv_promote_img0[l_addRes_166 + l_mulRes_170],
                                    glob->gv_promote_img0[l_addRes_167 + l_mulRes_170],
                                    glob->gv_promote_img0[l_addRes_168 + l_mulRes_170])),
                            vdot6(v_185,
                                vcons6(glob->gv_promote_img0[l_idx_161 + l_mulRes_171],
                                    glob->gv_promote_img0[l_addRes_164 + l_mulRes_171],
                                    glob->gv_promote_img0[l_addRes_165 + l_mulRes_171],
                                    glob->gv_promote_img0[l_addRes_166 + l_mulRes_171],
                                    glob->gv_promote_img0[l_addRes_167 + l_mulRes_171],
                                    glob->gv_promote_img0[l_addRes_168 + l_mulRes_171])),
                            vdot6(v_185,
                                vcons6(glob->gv_promote_img0[l_idx_161 + l_mulRes_172],
                                    glob->gv_promote_img0[l_addRes_164 + l_mulRes_172],
                                    glob->gv_promote_img0[l_addRes_165 + l_mulRes_172],
                                    glob->gv_promote_img0[l_addRes_166 + l_mulRes_172],
                                    glob->gv_promote_img0[l_addRes_167 + l_mulRes_172],
                                    glob->gv_promote_img0[l_addRes_168 + l_mulRes_172])),
                            vdot6(v_185,
                                vcons6(glob->gv_promote_img0[l_idx_161 + l_mulRes_173],
                                    glob->gv_promote_img0[l_addRes_164 + l_mulRes_173],
                                    glob->gv_promote_img0[l_addRes_165 + l_mulRes_173],
                                    glob->gv_promote_img0[l_addRes_166 + l_mulRes_173],
                                    glob->gv_promote_img0[l_addRes_167 + l_mulRes_173],
                                    glob->gv_promote_img0[l_addRes_168 + l_mulRes_173]))));
                    vec2 v_187 = vfloor2(v_157);
                    vec2 v_188 = v_157 - v_187;
                    diderot::array< int32_t, 2 > l_n_189 = vtoi2(v_187);
                    int32_t l_idx_190 = l_n_189[0] + -2;
                    int32_t l_idx_191 = l_n_189[1] + -2;
                    int32_t l_mulRes_192 = 70 * l_idx_191;
                    int32_t l_addRes_193 = l_idx_190 + 1;
                    int32_t l_addRes_194 = l_idx_190 + 2;
                    int32_t l_addRes_195 = l_idx_190 + 3;
                    int32_t l_addRes_196 = l_idx_190 + 4;
                    int32_t l_addRes_197 = l_idx_190 + 5;
                    int32_t l_mulRes_198 = 70 * (l_idx_191 + 1);
                    int32_t l_mulRes_199 = 70 * (l_idx_191 + 2);
                    int32_t l_mulRes_200 = 70 * (l_idx_191 + 3);
                    int32_t l_mulRes_201 = 70 * (l_idx_191 + 4);
                    int32_t l_mulRes_202 = 70 * (l_idx_191 + 5);
                    float l_vY__203 = v_188[1];
                    vec6 v_204 = vcons6(l_vY__203 + 0.2e1f, l_vY__203 + 0.1e1f, l_vY__203, l_vY__203 - 0.1e1f,
                        l_vY__203 - 0.2e1f, l_vY__203 - 0.3e1f);
                    float l_vX__205 = v_188[0];
                    vec6 v_206 = vcons6(l_vX__205 + 0.2e1f, l_vX__205 + 0.1e1f, l_vX__205, l_vX__205 - 0.1e1f,
                        l_vX__205 - 0.2e1f, l_vX__205 - 0.3e1f);
                    vec6 v_207 = v_176 + v_206 * (v_177 + v_206 * (v_178 + v_206 * (v_179 + v_206 * (v_180 + v_206 * (v_181 + v_206 * v_182)))));
                    float l__t_208 = vdot6(
                        v_176 + v_204 * (v_177 + v_204 * (v_178 + v_204 * (v_179 + v_204 * (v_180 + v_204 * (v_181 + v_204 * v_182))))),
                        vcons6(
                            vdot6(v_207,
                                vcons6(glob->gv_promote_img[l_idx_190 + l_mulRes_192],
                                    glob->gv_promote_img[l_addRes_193 + l_mulRes_192],
                                    glob->gv_promote_img[l_addRes_194 + l_mulRes_192],
                                    glob->gv_promote_img[l_addRes_195 + l_mulRes_192],
                                    glob->gv_promote_img[l_addRes_196 + l_mulRes_192],
                                    glob->gv_promote_img[l_addRes_197 + l_mulRes_192])),
                            vdot6(v_207,
                                vcons6(glob->gv_promote_img[l_idx_190 + l_mulRes_198],
                                    glob->gv_promote_img[l_addRes_193 + l_mulRes_198],
                                    glob->gv_promote_img[l_addRes_194 + l_mulRes_198],
                                    glob->gv_promote_img[l_addRes_195 + l_mulRes_198],
                                    glob->gv_promote_img[l_addRes_196 + l_mulRes_198],
                                    glob->gv_promote_img[l_addRes_197 + l_mulRes_198])),
                            vdot6(v_207,
                                vcons6(glob->gv_promote_img[l_idx_190 + l_mulRes_199],
                                    glob->gv_promote_img[l_addRes_193 + l_mulRes_199],
                                    glob->gv_promote_img[l_addRes_194 + l_mulRes_199],
                                    glob->gv_promote_img[l_addRes_195 + l_mulRes_199],
                                    glob->gv_promote_img[l_addRes_196 + l_mulRes_199],
                                    glob->gv_promote_img[l_addRes_197 + l_mulRes_199])),
                            vdot6(v_207,
                                vcons6(glob->gv_promote_img[l_idx_190 + l_mulRes_200],
                                    glob->gv_promote_img[l_addRes_193 + l_mulRes_200],
                                    glob->gv_promote_img[l_addRes_194 + l_mulRes_200],
                                    glob->gv_promote_img[l_addRes_195 + l_mulRes_200],
                                    glob->gv_promote_img[l_addRes_196 + l_mulRes_200],
                                    glob->gv_promote_img[l_addRes_197 + l_mulRes_200])),
                            vdot6(v_207,
                                vcons6(glob->gv_promote_img[l_idx_190 + l_mulRes_201],
                                    glob->gv_promote_img[l_addRes_193 + l_mulRes_201],
                                    glob->gv_promote_img[l_addRes_194 + l_mulRes_201],
                                    glob->gv_promote_img[l_addRes_195 + l_mulRes_201],
                                    glob->gv_promote_img[l_addRes_196 + l_mulRes_201],
                                    glob->gv_promote_img[l_addRes_197 + l_mulRes_201])),
                            vdot6(v_207,
                                vcons6(glob->gv_promote_img[l_idx_190 + l_mulRes_202],
                                    glob->gv_promote_img[l_addRes_193 + l_mulRes_202],
                                    glob->gv_promote_img[l_addRes_194 + l_mulRes_202],
                                    glob->gv_promote_img[l_addRes_195 + l_mulRes_202],
                                    glob->gv_promote_img[l_addRes_196 + l_mulRes_202],
                                    glob->gv_promote_img[l_addRes_197 + l_mulRes_202]))));
                    v_209 = vcons3(l__t_186, l__t_208, std::max(l__t_186, l__t_208));
                }
                else {
                    v_209 = vload3(tensor_ref_3(self->sv_out).addr(0));
                }
                if (glob->gv_dx == 1) {
                    vec2 v_210 = vfloor2(v_156);
                    vec2 v_211 = v_156 - v_210;
                    diderot::array< int32_t, 2 > l_n_212 = vtoi2(v_210);
                    int32_t l_idx_213 = l_n_212[0] + -2;
                    int32_t l_idx_214 = l_n_212[1] + -2;
                    int32_t l_mulRes_215 = 70 * l_idx_214;
                    int32_t l_addRes_216 = l_idx_213 + 1;
                    int32_t l_addRes_217 = l_idx_213 + 2;
                    int32_t l_addRes_218 = l_idx_213 + 3;
                    int32_t l_addRes_219 = l_idx_213 + 4;
                    int32_t l_addRes_220 = l_idx_213 + 5;
                    vec6 v_221 = vcons6(glob->gv_promote_img0[l_idx_213 + l_mulRes_215],
                        glob->gv_promote_img0[l_addRes_216 + l_mulRes_215],
                        glob->gv_promote_img0[l_addRes_217 + l_mulRes_215],
                        glob->gv_promote_img0[l_addRes_218 + l_mulRes_215],
                        glob->gv_promote_img0[l_addRes_219 + l_mulRes_215],
                        glob->gv_promote_img0[l_addRes_220 + l_mulRes_215]);
                    int32_t l_mulRes_222 = 70 * (l_idx_214 + 1);
                    vec6 v_223 = vcons6(glob->gv_promote_img0[l_idx_213 + l_mulRes_222],
                        glob->gv_promote_img0[l_addRes_216 + l_mulRes_222],
                        glob->gv_promote_img0[l_addRes_217 + l_mulRes_222],
                        glob->gv_promote_img0[l_addRes_218 + l_mulRes_222],
                        glob->gv_promote_img0[l_addRes_219 + l_mulRes_222],
                        glob->gv_promote_img0[l_addRes_220 + l_mulRes_222]);
                    int32_t l_mulRes_224 = 70 * (l_idx_214 + 2);
                    vec6 v_225 = vcons6(glob->gv_promote_img0[l_idx_213 + l_mulRes_224],
                        glob->gv_promote_img0[l_addRes_216 + l_mulRes_224],
                        glob->gv_promote_img0[l_addRes_217 + l_mulRes_224],
                        glob->gv_promote_img0[l_addRes_218 + l_mulRes_224],
                        glob->gv_promote_img0[l_addRes_219 + l_mulRes_224],
                        glob->gv_promote_img0[l_addRes_220 + l_mulRes_224]);
                    int32_t l_mulRes_226 = 70 * (l_idx_214 + 3);
                    vec6 v_227 = vcons6(glob->gv_promote_img0[l_idx_213 + l_mulRes_226],
                        glob->gv_promote_img0[l_addRes_216 + l_mulRes_226],
                        glob->gv_promote_img0[l_addRes_217 + l_mulRes_226],
                        glob->gv_promote_img0[l_addRes_218 + l_mulRes_226],
                        glob->gv_promote_img0[l_addRes_219 + l_mulRes_226],
                        glob->gv_promote_img0[l_addRes_220 + l_mulRes_226]);
                    int32_t l_mulRes_228 = 70 * (l_idx_214 + 4);
                    vec6 v_229 = vcons6(glob->gv_promote_img0[l_idx_213 + l_mulRes_228],
                        glob->gv_promote_img0[l_addRes_216 + l_mulRes_228],
                        glob->gv_promote_img0[l_addRes_217 + l_mulRes_228],
                        glob->gv_promote_img0[l_addRes_218 + l_mulRes_228],
                        glob->gv_promote_img0[l_addRes_219 + l_mulRes_228],
                        glob->gv_promote_img0[l_addRes_220 + l_mulRes_228]);
                    int32_t l_mulRes_230 = 70 * (l_idx_214 + 5);
                    vec6 v_231 = vcons6(glob->gv_promote_img0[l_idx_213 + l_mulRes_230],
                        glob->gv_promote_img0[l_addRes_216 + l_mulRes_230],
                        glob->gv_promote_img0[l_addRes_217 + l_mulRes_230],
                        glob->gv_promote_img0[l_addRes_218 + l_mulRes_230],
                        glob->gv_promote_img0[l_addRes_219 + l_mulRes_230],
                        glob->gv_promote_img0[l_addRes_220 + l_mulRes_230]);
                    float l_vY__232 = v_211[1];
                    vec6 v_233 = vcons6(l_vY__232 + 0.2e1f, l_vY__232 + 0.1e1f, l_vY__232, l_vY__232 - 0.1e1f,
                        l_vY__232 - 0.2e1f, l_vY__232 - 0.3e1f);
                    vec6 v_234 = vcons6(0.961875e1f, 0.1875e-1f, 0.8625e0f, 0.8625e0f, 0.1875e-1f, 0.961875e1f);
                    vec6 v_235 = vcons6(-0.23625e2f, 0.4375e1f, 0.0f, 0.0f, -0.4375e1f, 0.23625e2f);
                    vec6 v_236 = vcons6(0.2334375e2f, -0.1065625e2f, -0.14375e1f, -0.14375e1f, -0.1065625e2f,
                        0.2334375e2f);
                    vec6 v_237 = vcons6(-0.12e2f, 0.10e2f, 0.0f, 0.0f, -0.10e2f, 0.12e2f);
                    vec6 v_238 = vcons6(0.340625e1f, -0.459375e1f, 0.11875e1f, 0.11875e1f, -0.459375e1f, 0.340625e1f);
                    vec6 v_239 = vcons6(-0.508333333333e0f, 0.104166666667e1f, -0.583333333333e0f, 0.583333333333e0f,
                        -0.104166666667e1f, 0.508333333333e0f);
                    vec6 v_240 = vcons6(0.3125e-1f, -0.9375e-1f, 0.625e-1f, 0.625e-1f, -0.9375e-1f, 0.3125e-1f);
                    vec6 v_241 = v_234 + v_233 * (v_235 + v_233 * (v_236 + v_233 * (v_237 + v_233 * (v_238 + v_233 * (v_239 + v_233 * v_240)))));
                    float l_vX__242 = v_211[0];
                    vec6 v_243 = vcons6(l_vX__242 + 0.2e1f, l_vX__242 + 0.1e1f, l_vX__242, l_vX__242 - 0.1e1f,
                        l_vX__242 - 0.2e1f, l_vX__242 - 0.3e1f);
                    vec6 v_244 = v_234 + v_243 * (v_235 + v_243 * (v_236 + v_243 * (v_237 + v_243 * (v_238 + v_243 * (v_239 + v_243 * v_240)))));
                    vec6 v_245 = vcons6(vdot6(v_244, v_221), vdot6(v_244, v_223), vdot6(v_244, v_225),
                        vdot6(v_244, v_227), vdot6(v_244, v_229), vdot6(v_244, v_231));
                    float l_probe_l_5_246 = vdot6(v_241, v_245);
                    vec2 v_247 = vfloor2(v_157);
                    vec2 v_248 = v_157 - v_247;
                    diderot::array< int32_t, 2 > l_n_249 = vtoi2(v_247);
                    int32_t l_idx_250 = l_n_249[0] + -2;
                    int32_t l_idx_251 = l_n_249[1] + -2;
                    int32_t l_mulRes_252 = 70 * l_idx_251;
                    int32_t l_addRes_253 = l_idx_250 + 1;
                    int32_t l_addRes_254 = l_idx_250 + 2;
                    int32_t l_addRes_255 = l_idx_250 + 3;
                    int32_t l_addRes_256 = l_idx_250 + 4;
                    int32_t l_addRes_257 = l_idx_250 + 5;
                    vec6 v_258 = vcons6(glob->gv_promote_img[l_idx_250 + l_mulRes_252],
                        glob->gv_promote_img[l_addRes_253 + l_mulRes_252],
                        glob->gv_promote_img[l_addRes_254 + l_mulRes_252],
                        glob->gv_promote_img[l_addRes_255 + l_mulRes_252],
                        glob->gv_promote_img[l_addRes_256 + l_mulRes_252],
                        glob->gv_promote_img[l_addRes_257 + l_mulRes_252]);
                    int32_t l_mulRes_259 = 70 * (l_idx_251 + 1);
                    vec6 v_260 = vcons6(glob->gv_promote_img[l_idx_250 + l_mulRes_259],
                        glob->gv_promote_img[l_addRes_253 + l_mulRes_259],
                        glob->gv_promote_img[l_addRes_254 + l_mulRes_259],
                        glob->gv_promote_img[l_addRes_255 + l_mulRes_259],
                        glob->gv_promote_img[l_addRes_256 + l_mulRes_259],
                        glob->gv_promote_img[l_addRes_257 + l_mulRes_259]);
                    int32_t l_mulRes_261 = 70 * (l_idx_251 + 2);
                    vec6 v_262 = vcons6(glob->gv_promote_img[l_idx_250 + l_mulRes_261],
                        glob->gv_promote_img[l_addRes_253 + l_mulRes_261],
                        glob->gv_promote_img[l_addRes_254 + l_mulRes_261],
                        glob->gv_promote_img[l_addRes_255 + l_mulRes_261],
                        glob->gv_promote_img[l_addRes_256 + l_mulRes_261],
                        glob->gv_promote_img[l_addRes_257 + l_mulRes_261]);
                    int32_t l_mulRes_263 = 70 * (l_idx_251 + 3);
                    vec6 v_264 = vcons6(glob->gv_promote_img[l_idx_250 + l_mulRes_263],
                        glob->gv_promote_img[l_addRes_253 + l_mulRes_263],
                        glob->gv_promote_img[l_addRes_254 + l_mulRes_263],
                        glob->gv_promote_img[l_addRes_255 + l_mulRes_263],
                        glob->gv_promote_img[l_addRes_256 + l_mulRes_263],
                        glob->gv_promote_img[l_addRes_257 + l_mulRes_263]);
                    int32_t l_mulRes_265 = 70 * (l_idx_251 + 4);
                    vec6 v_266 = vcons6(glob->gv_promote_img[l_idx_250 + l_mulRes_265],
                        glob->gv_promote_img[l_addRes_253 + l_mulRes_265],
                        glob->gv_promote_img[l_addRes_254 + l_mulRes_265],
                        glob->gv_promote_img[l_addRes_255 + l_mulRes_265],
                        glob->gv_promote_img[l_addRes_256 + l_mulRes_265],
                        glob->gv_promote_img[l_addRes_257 + l_mulRes_265]);
                    int32_t l_mulRes_267 = 70 * (l_idx_251 + 5);
                    vec6 v_268 = vcons6(glob->gv_promote_img[l_idx_250 + l_mulRes_267],
                        glob->gv_promote_img[l_addRes_253 + l_mulRes_267],
                        glob->gv_promote_img[l_addRes_254 + l_mulRes_267],
                        glob->gv_promote_img[l_addRes_255 + l_mulRes_267],
                        glob->gv_promote_img[l_addRes_256 + l_mulRes_267],
                        glob->gv_promote_img[l_addRes_257 + l_mulRes_267]);
                    float l_vY__269 = v_248[1];
                    vec6 v_270 = vcons6(l_vY__269 + 0.2e1f, l_vY__269 + 0.1e1f, l_vY__269, l_vY__269 - 0.1e1f,
                        l_vY__269 - 0.2e1f, l_vY__269 - 0.3e1f);
                    vec6 v_271 = v_234 + v_270 * (v_235 + v_270 * (v_236 + v_270 * (v_237 + v_270 * (v_238 + v_270 * (v_239 + v_270 * v_240)))));
                    float l_vX__272 = v_248[0];
                    vec6 v_273 = vcons6(l_vX__272 + 0.2e1f, l_vX__272 + 0.1e1f, l_vX__272, l_vX__272 - 0.1e1f,
                        l_vX__272 - 0.2e1f, l_vX__272 - 0.3e1f);
                    vec6 v_274 = v_234 + v_273 * (v_235 + v_273 * (v_236 + v_273 * (v_237 + v_273 * (v_238 + v_273 * (v_239 + v_273 * v_240)))));
                    vec6 v_275 = vcons6(vdot6(v_274, v_258), vdot6(v_274, v_260), vdot6(v_274, v_262),
                        vdot6(v_274, v_264), vdot6(v_274, v_266), vdot6(v_274, v_268));
                    float l_probe_l_6_276 = vdot6(v_271, v_275);
                    vec6 v_277 = vcons6(0.466875e2f, -0.213125e2f, -0.2875e1f, -0.2875e1f, -0.213125e2f, 0.466875e2f);
                    vec6 v_278 = vcons6(-0.36e2f, 0.30e2f, 0.0f, 0.0f, -0.30e2f, 0.36e2f);
                    vec6 v_279 = vcons6(0.13625e2f, -0.18375e2f, 0.475e1f, 0.475e1f, -0.18375e2f, 0.13625e2f);
                    vec6 v_280 = vcons6(-0.254166666667e1f, 0.520833333333e1f, -0.291666666667e1f, 0.291666666667e1f,
                        -0.520833333333e1f, 0.254166666667e1f);
                    vec6 v_281 = vcons6(0.1875e0f, -0.5625e0f, 0.375e0f, 0.375e0f, -0.5625e0f, 0.1875e0f);
                    vec6 v_282 = v_235 + v_243 * (v_277 + v_243 * (v_278 + v_243 * (v_279 + v_243 * (v_280 + v_243 * v_281))));
                    vec2 v_283 = vcons2(
                        vdot6(v_241,
                            vcons6(vdot6(v_282, v_221), vdot6(v_282, v_223), vdot6(v_282, v_225), vdot6(v_282, v_227),
                                vdot6(v_282, v_229), vdot6(v_282, v_231))),
                        vdot6(
                            v_235 + v_233 * (v_277 + v_233 * (v_278 + v_233 * (v_279 + v_233 * (v_280 + v_233 * v_281)))),
                            v_245));
                    vec6 v_284 = v_235 + v_273 * (v_277 + v_273 * (v_278 + v_273 * (v_279 + v_273 * (v_280 + v_273 * v_281))));
                    vec2 v_285 = vcons2(
                        vdot6(v_271,
                            vcons6(vdot6(v_284, v_258), vdot6(v_284, v_260), vdot6(v_284, v_262), vdot6(v_284, v_264),
                                vdot6(v_284, v_266), vdot6(v_284, v_268))),
                        vdot6(
                            v_235 + v_270 * (v_277 + v_270 * (v_278 + v_270 * (v_279 + v_270 * (v_280 + v_270 * v_281)))),
                            v_275));
                    bool l_r_286 = l_probe_l_5_246 > l_probe_l_6_276;
                    vec2 v_287 = vcons2(
                        IfWrap(l_r_286, vdot2(v_283, vcons2(l_Mtransform_152[0], l_Mtransform_152[2])),
                            vdot2(v_285, vcons2(l_Mtransform_154[0], l_Mtransform_154[2]))),
                        IfWrap(l_r_286, vdot2(v_283, vcons2(l_Mtransform_152[1], l_Mtransform_152[3])),
                            vdot2(v_285, vcons2(l_Mtransform_154[1], l_Mtransform_154[3]))));
                    v_288 = vcons3(v_287[0], v_287[1], std::max(l_probe_l_5_246, l_probe_l_6_276));
                }
                else {
                    v_288 = v_209;
                }
                v_289 = v_288;
            }
            else {
                v_289 = vload3(tensor_ref_3(self->sv_out).addr(0));
            }
            v_290 = v_289;
        }
        else {
            v_290 = vload3(tensor_ref_3(self->sv_out).addr(0));
        }
        v_151 = v_290;
    }
    vpack2(self->sv_pos, v_8);
    vpack3(self->sv_out, v_151);
    return diderot::kStabilize;
}
bool output_get_out (world *wrld, Nrrd *nData)
{
    // Compute sizes of nrrd file
    size_t sizes[2];
    sizes[0] = 3;
    sizes[1] = wrld->_size[0];
    // Allocate nData nrrd
    if (nrrdMaybeAlloc_nva(nData, nrrdTypeFloat, 2, sizes) != 0) {
        char *msg = biffGetDone(NRRD);
        biffMsgAdd(wrld->_errors, msg);
        std::free(msg);
        return true;
    }
    // copy data to output nrrd
    char *cp = reinterpret_cast<char *>(nData->data);
    for (auto ix = wrld->_strands.begin_alive(); ix != wrld->_strands.end_alive(); ix = wrld->_strands.next_alive(ix)) {
        memcpy(cp, &wrld->_strands.strand(ix)->sv_out, 3 * sizeof(float));
        cp += 3 * sizeof(float);
    }
    nData->axis[0].kind = nrrdKind3Vector;
    nData->axis[1].kind = nrrdKindSpace;
    return false;
}
static void write_output (world *wrld)
{
    Nrrd *nData;
    nData = nrrdNew();
    if (output_get_out(wrld, nData)) {
        std::cerr << "Error getting nrrd data:\n" << biffMsgStrGet(wrld->_errors) << std::endl;
        delete wrld;
        exit(1);
    }
    else if (nrrd_save_helper(OutputFile, nData)) {
        exit(1);
    }
    nrrdNuke(nData);
}
/*---------- begin world-methods.in ----------*/
// Allocate the program's world
//
world::world ()
    : diderot::world_base (ProgramName, true, 1)
{
#ifndef DIDEROT_NO_GLOBALS
    this->_globals = new globals;
#endif

#ifdef DIDEROT_HAS_STRAND_COMMUNICATION
    this->_tree = nullptr;
#endif
} // world constructor

// shutdown and deallocate the world
//
world::~world ()
{
#ifndef DIDEROT_NO_GLOBALS
    delete this->_globals;
#endif

#ifdef DIDEROT_HAS_STRAND_COMMUNICATION
    delete this->_tree;
#endif

} // world destructor

// Initialize the program's world
//
bool world::init ()
{
    if (this->_stage != diderot::POST_NEW) {
        biffMsgAdd (this->_errors, "multiple calls to world::init");
        return true;
    }

#if !defined(DIDEROT_STANDALONE_EXEC) && !defined(DIDEROT_NO_INPUTS)
  // initialize the defined flags for the input globals
    init_defined_inputs (this);
#endif

    this->_stage = diderot::POST_INIT;

    return false;

}

// allocate the initial strands and initialize the rest of the world structure.
//
bool world::alloc (int32_t base[1], uint32_t size[1])
{
    size_t numStrands = 1;
    for (uint32_t i = 0;  i < 1;  i++) {
        numStrands *= size[i];
        this->_base[i] = base[i];
        this->_size[i] = size[i];
    }

    if (this->_verbose) {
        std::cerr << "world::alloc: " << size[0];
        for (uint32_t i = 1;  i < 1;  i++) {
            std::cerr << " x " << size[i];
        }
        std::cerr << std::endl;
    }

#ifdef DIDEROT_TARGET_PARALLEL
  // determine the block size based on the initial number of strands and the
  // number of workers
    this->_strands.set_block_size (this->_sched->_numWorkers, numStrands);
#endif

  // allocate the strand array
    if (this->_strands.alloc (numStrands)) {
        biffMsgAdd (this->_errors, "unable to allocate strand-state array\n");
        return true;
    }

  // initialize strand state pointers etc.
    this->_strands.create_strands (numStrands);

#ifdef DIDEROT_HAS_STRAND_COMMUNICATION
    this->_tree = new diderot::kdtree<0, float, strand_array> (&this->_strands);
#endif

    return false;

} // world::alloc

// swap input and output states
//
inline void world::swap_state ()
{
    this->_strands.swap ();
}

#ifdef DIDEROT_HAS_KILL_ALL
void world::kill_all ()
{
    if (this->_strands.num_active() > 0) {
        for (auto ix = this->_strands.begin_active();
            ix != this->_strands.end_active();
            )
        {
            assert (this->_strands.status(ix) == diderot::kActive);
            ix = this->_strands.kill (ix);
        }
        this->_strands.finish_kill_all();
    }
    assert (this->_strands.num_active() == 0);
}
#endif

#ifdef DIDEROT_HAS_STABILIZE_ALL
void world::stabilize_all ()
{
#ifndef DIDEROT_NO_GLOBALS
    globals *glob = this->_globals;
#endif

    if (this->_strands.num_active() > 0) {
        for (auto ix = this->_strands.begin_active();
            ix != this->_strands.end_active();
            )
        {
            assert (this->_strands.status(ix) == diderot::kActive);
	    this->_strands._status[ix] = diderot::kStable;
            ix = this->_strands.strand_stabilize (ix);
        }
        this->_strands.finish_stabilize_all();
    }
    assert (this->_strands.num_active() == 0);
}
#endif
/*---------- end world-methods.in ----------*/

bool world::create_strands ()
{
    if (init_globals(this)) {
        return true;
    }
    globals *glob = this->_globals;
    int lo_0 = 0;
    int hi_1 = glob->gv_outSize - 1;
    int32_t base[1] = {lo_0,};
    uint32_t size[1] = {static_cast<uint32_t>(hi_1 - lo_0 + 1),};
    if (this->alloc(base, size)) {
        return true;
    }
    uint32_t ix = 0;
    for (int i_i_293 = lo_0; i_i_293 <= hi_1; i_i_293++) {
        sample_init(this->_strands.strand(ix), i_i_293);
        ++ix;
    }
    this->swap_state();
    this->_stage = diderot::POST_CREATE;
    return false;
}
/*---------- begin seq-run-nobsp.in ----------*/
//! Run the Diderot program (sequential version without BSP semantics)
//! \param max_nsteps the limit on the number of super steps; 0 means unlimited
//! \return the number of steps taken, or 0 on error.
uint32_t world::run (uint32_t max_nsteps)
{
    if (this->_stage < diderot::POST_CREATE) {
        biffMsgAdd (this->_errors, "attempt to run uninitialized program\n");
        return 0;
    }
    else if (this->_stage == diderot::DONE) {
        return 0;
    }
    else if (this->_stage == diderot::POST_CREATE) {
#ifdef DIDEROT_HAS_GLOBAL_START
        this->global_start();
#endif
        this->_stage = diderot::RUNNING;
    }
    assert (this->_stage == diderot::RUNNING);

#ifndef DIDEROT_NO_GLOBALS
    globals *glob = this->_globals;
#endif

    if (max_nsteps == 0) {
        max_nsteps = 0xffffffff;  // essentially unlimited
    }

    double t0 = airTime();

    if (this->_verbose) {
        std::cerr << "run with " << this->_strands.num_alive() << " strands ..." << std::endl;
    }

#ifdef DIDEROT_HAS_START_METHOD
    this->run_start_methods();
#endif

  // iterate until all strands are stable
    uint32_t maxSteps = 0;
    for (auto ix = this->_strands.begin_active();
         ix != this->_strands.end_active();
         )
    {
        diderot::strand_status sts = this->_strands.status(ix);
        uint32_t nSteps = 0;
        while ((! sts) && (nSteps < max_nsteps)) {
            nSteps++;
            sts = this->_strands.strand_update(glob, ix);
        }
        switch (sts) {
          case diderot::kStabilize:
          // stabilize the strand's state.
            ix = this->_strands.strand_stabilize (ix);
            break;
#ifdef DIDEROT_HAS_STRAND_DIE
          case diderot::kDie:
            ix = this->_strands.kill (ix);
            break;
#endif
          default:
            assert (sts == this->_strands.status(ix));
	    ix = this->_strands.next_active(ix);
            break;
        }
        if (maxSteps < nSteps) maxSteps = nSteps;
    }

    this->_run_time += airTime() - t0;

    if (this->_strands.num_active() == 0)
        this->_stage = diderot::DONE;

    return maxSteps;

} // world::run
/*---------- end seq-run-nobsp.in ----------*/

/*---------- begin namespace-close.in ----------*/

} // namespace Diderot
/*---------- end namespace-close.in ----------*/

/*---------- begin seq-main.in ----------*/
using namespace Diderot;

//! Main function for standalone sequential C target
//
int main (int argc, const char **argv)
{
    bool        timingFlg = false;      //! true if timing computation
    uint32_t    stepLimit = 0;          //! limit on number of execution steps (0 means unlimited)
    std::string printFile = "-";        //! file to direct printed output into
#ifdef DIDEROT_EXEC_SNAPSHOT
    uint32_t    snapshotPeriod = 0;     //! supersteps per snapshot; 0 means no snapshots
#endif
    uint32_t    nSteps = 0;             //! number of supersteps taken

  // create the world
    world *wrld = new (std::nothrow) world();
    if (wrld == nullptr) {
        std::cerr << "unable to create world" << std::endl;
        exit(1);
    }

#ifndef DIDEROT_NO_INPUTS
  // initialize the default values for the inputs
    cmd_line_inputs inputs;
    init_defaults (&inputs);
#endif

  // handle command-line options
    {
        diderot::options *opts = new diderot::options ();
        opts->add ("l,limit", "specify limit on number of super-steps (0 means unlimited)",
            &stepLimit, true);
#ifdef DIDEROT_EXEC_SNAPSHOT
        opts->add ("s,snapshot",
            "specify number of super-steps per snapshot (0 means no snapshots)",
            &snapshotPeriod, true);
#endif
        opts->add ("print", "specify where to direct printed output", &printFile, true);
        opts->addFlag ("v,verbose", "enable runtime-system messages", &(wrld->_verbose));
        opts->addFlag ("t,timing", "enable execution timing", &timingFlg);
#ifndef DIDEROT_NO_INPUTS
      // register options for setting global inputs
        register_inputs (&inputs, opts);
#endif
        register_outputs (opts);
        opts->process (argc, argv);
        delete opts;
    }

  // redirect printing (if necessary)
    if (printFile.compare("-") != 0) {
        wrld->_printTo = new std::ofstream (printFile);
        if (wrld->_printTo->fail()) {
            std::cerr << "Error opening print file" << std::endl;
            delete wrld;
            exit(1);
        }
    }

  // initialize scheduler stuff
    if (wrld->_verbose) {
        std::cerr << "initializing world ..." << std::endl;
    }
    if (wrld->init()) {
        std::cerr << "Error initializing world:\n" << wrld->get_errors() << std::endl;
	delete wrld;
        exit(1);
    }

#ifndef DIDEROT_NO_INPUTS
  // initialize the input globals
    if (init_inputs (wrld, &inputs)) {
        std::cerr << "Error initializing inputs:\n" << wrld->get_errors() << std::endl;
	delete wrld;
        exit(1);
    }
#endif

  // run the generated global initialization code
    if (wrld->_verbose) {
        std::cerr << "initializing globals and creating strands ...\n";
    }
    if (wrld->create_strands()) {
        std::cerr << "Error in global initialization:\n"
            << wrld->get_errors() << std::endl;
	delete wrld;
        exit(1);
    }

#ifdef DIDEROT_EXEC_SNAPSHOT

    if (snapshotPeriod > 0) {
     // write initial state as snapshot 0
        write_snapshot (wrld, "-0000");
     // run the program for `snapshotPeriod` steps at a time with a snapshot after each run
        while (true) {
            uint32_t n, limit;
          // determine a step limit for the next run
            if (stepLimit > 0) {
                if (stepLimit <= nSteps) {
                    break;
                }
                limit = std::min(stepLimit - nSteps, snapshotPeriod);
            }
            else {
                limit = snapshotPeriod;
            }
          // run the program for upto limit steps
            if ((n = wrld->run (limit)) == 0) {
                break;
            }
            nSteps += n;
            if ((wrld->_errors->errNum > 0) || (wrld->_strands.num_alive() == 0)) {
                break;
            }
          // write a snapshot with the step count as a suffix
            std::string suffix = std::to_string(nSteps);
            if (suffix.length() < 4) {
                suffix = std::string("0000").substr(0, 4 - suffix.length()) + suffix;
            }
            suffix = "-" + suffix;
            write_snapshot (wrld, suffix);
        }
    }
    else {
        nSteps = wrld->run (stepLimit);
    }

#else // !DIDEROT_EXEC_SNAPSHOT

    nSteps = wrld->run (stepLimit);

#endif // DIDEROT_EXEC_SNAPSHOT

    if (wrld->_errors->errNum > 0) {
        std::cerr << "Error during execution:\n" << wrld->get_errors() << std::endl;
	delete wrld;
        exit(1);
    }

    if ((stepLimit != 0) && (wrld->_strands.num_active() > 0)) {
#ifdef DIDEROT_STRAND_ARRAY
        if (wrld->_verbose) {
            std::cerr << "Step limit expired; "
                << wrld->_strands.num_active() << " active strands remaining" << std::endl;
        }
#else
      // step limit expired, so kill remaining strands
        if (wrld->_verbose) {
            std::cerr << "Step limit expired. Killing remaining "
                << wrld->_strands.num_active() << " active strands" << std::endl;
        }
        wrld->kill_all();
#endif
    }

    if (wrld->_verbose) {
        std::cerr << "done: " << nSteps << " steps, in " << wrld->_run_time << " seconds"
            << std::endl;
    }
    else if (timingFlg) {
        std::cout << "usr=" << wrld->_run_time << std::endl;
    }

  // output the final strand states
    write_output (wrld);

    delete wrld;

    return 0;

} // main
/*---------- end seq-main.in ----------*/

