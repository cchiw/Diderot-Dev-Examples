/*---------- begin exec-head.in ----------*/
/*! \file maxgrad1.cxx
 *
 * Generated from maxgrad1.diderot.
 *
 * Command: /Users/chariseechiw/diderot/chiw17/bin/diderotc --exec maxgrad1.diderot
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

static std::string ProgramName = "maxgrad1";

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
    diderot::image2d< float, float > gv_promote_img0;
    diderot::image2d< float, float > gv_promote_img;
    int32_t gv_outSize;
    ~globals ()
    {
        this->gv_promote_img0.free_data();
        this->gv_promote_img.free_data();
    }
};
struct sample_strand {
    tensor_2 sv_pos;
    tensor_2 sv_out;
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
template <typename TY>
inline bool inside2Ds3 (vec2 x0, diderot::image2d< float, TY > img)
{
    return 2 < x0[0] && x0[1] < img.size(1) - 3 && 2 < x0[1] && x0[0] < img.size(0) - 3;
}
inline void vpack2 (tensor_2 &dst, vec2 v0)
{
    dst._data[0] = v0[0];
    dst._data[1] = v0[1];
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
    diderot::image2d< float, float > l_promote_img0_0;
    diderot::image2d< float, float > l_promote_img_1;
    globals *glob = wrld->_globals;
    if (l_promote_img0_0.load(wrld, "../../data/y7.nrrd")) {
        return true;
    }
    glob->gv_promote_img0 = l_promote_img0_0;
    if (l_promote_img_1.load(wrld, "../../data/xy7.nrrd")) {
        return true;
    }
    glob->gv_promote_img = l_promote_img_1;
    glob->gv_outSize = 5;
    return false;
}
static void sample_init (sample_strand *self, int32_t p_i_2)
{
    float l__t_3 = static_cast<float>(p_i_2);
    self->sv_pos[0] = l__t_3;
    self->sv_pos[1] = l__t_3;
    self->sv_out[0] = -0.77e2f;
    self->sv_out[1] = -0.77e2f;
    self->sv_i = p_i_2;
}
static diderot::strand_status sample_update (globals *glob, sample_strand *self)
{
    vec2 v_6;
    vec2 v_92;
    if (self->sv_i == 0) {
        v_6 = vcons2(0.1e0f, 0.1e0f);
    }
    else {
        vec2 v_7;
        if (self->sv_i == 1) {
            v_7 = vcons2(0.2e0f, 0.2e0f);
        }
        else {
            vec2 v_8;
            if (self->sv_i == 2) {
                v_8 = vcons2(-0.2e0f, -0.2e0f);
            }
            else {
                vec2 v_9;
                if (self->sv_i == 3) {
                    v_9 = vcons2(-0.4e0f, -0.4e0f);
                }
                else {
                    vec2 v_10;
                    if (self->sv_i == 4) {
                        v_10 = vcons2(0.4e0f, 0.4e0f);
                    }
                    else {
                        v_10 = vload2(tensor_ref_2(self->sv_pos).addr(0));
                    }
                    v_9 = v_10;
                }
                v_8 = v_9;
            }
            v_7 = v_8;
        }
        v_6 = v_7;
    }
    tensor_ref_2_2 l_Mtransform_11 = world2image(glob->gv_promote_img0);
    vec2 v_12 = vcons2(vdot2(vload2(l_Mtransform_11.last(0).addr(0)), v_6),
        vdot2(vload2(l_Mtransform_11.last(2).addr(0)), v_6)) + vload2(translate(glob->gv_promote_img0).addr(0));
    tensor_ref_2_2 l_Mtransform_13 = world2image(glob->gv_promote_img);
    vec2 v_14 = vcons2(vdot2(vload2(l_Mtransform_13.last(0).addr(0)), v_6),
        vdot2(vload2(l_Mtransform_13.last(2).addr(0)), v_6)) + vload2(translate(glob->gv_promote_img).addr(0));
    vec2 v_15 = v_12;
    vec2 v_16 = v_14;
    if (inside2Ds3(v_12, glob->gv_promote_img0) && inside2Ds3(v_14, glob->gv_promote_img)) {
        vec2 v_17 = vfloor2(v_15);
        vec2 v_18 = v_15 - v_17;
        diderot::array< int32_t, 2 > l_n_19 = vtoi2(v_17);
        int32_t l_idx_20 = l_n_19[0] + -2;
        int32_t l_idx_21 = l_n_19[1] + -2;
        int32_t l_mulRes_22 = 70 * l_idx_21;
        int32_t l_addRes_23 = l_idx_20 + 1;
        int32_t l_addRes_24 = l_idx_20 + 2;
        int32_t l_addRes_25 = l_idx_20 + 3;
        int32_t l_addRes_26 = l_idx_20 + 4;
        int32_t l_addRes_27 = l_idx_20 + 5;
        vec6 v_28 = vcons6(glob->gv_promote_img0[l_idx_20 + l_mulRes_22],
            glob->gv_promote_img0[l_addRes_23 + l_mulRes_22], glob->gv_promote_img0[l_addRes_24 + l_mulRes_22],
            glob->gv_promote_img0[l_addRes_25 + l_mulRes_22], glob->gv_promote_img0[l_addRes_26 + l_mulRes_22],
            glob->gv_promote_img0[l_addRes_27 + l_mulRes_22]);
        int32_t l_mulRes_29 = 70 * (l_idx_21 + 1);
        vec6 v_30 = vcons6(glob->gv_promote_img0[l_idx_20 + l_mulRes_29],
            glob->gv_promote_img0[l_addRes_23 + l_mulRes_29], glob->gv_promote_img0[l_addRes_24 + l_mulRes_29],
            glob->gv_promote_img0[l_addRes_25 + l_mulRes_29], glob->gv_promote_img0[l_addRes_26 + l_mulRes_29],
            glob->gv_promote_img0[l_addRes_27 + l_mulRes_29]);
        int32_t l_mulRes_31 = 70 * (l_idx_21 + 2);
        vec6 v_32 = vcons6(glob->gv_promote_img0[l_idx_20 + l_mulRes_31],
            glob->gv_promote_img0[l_addRes_23 + l_mulRes_31], glob->gv_promote_img0[l_addRes_24 + l_mulRes_31],
            glob->gv_promote_img0[l_addRes_25 + l_mulRes_31], glob->gv_promote_img0[l_addRes_26 + l_mulRes_31],
            glob->gv_promote_img0[l_addRes_27 + l_mulRes_31]);
        int32_t l_mulRes_33 = 70 * (l_idx_21 + 3);
        vec6 v_34 = vcons6(glob->gv_promote_img0[l_idx_20 + l_mulRes_33],
            glob->gv_promote_img0[l_addRes_23 + l_mulRes_33], glob->gv_promote_img0[l_addRes_24 + l_mulRes_33],
            glob->gv_promote_img0[l_addRes_25 + l_mulRes_33], glob->gv_promote_img0[l_addRes_26 + l_mulRes_33],
            glob->gv_promote_img0[l_addRes_27 + l_mulRes_33]);
        int32_t l_mulRes_35 = 70 * (l_idx_21 + 4);
        vec6 v_36 = vcons6(glob->gv_promote_img0[l_idx_20 + l_mulRes_35],
            glob->gv_promote_img0[l_addRes_23 + l_mulRes_35], glob->gv_promote_img0[l_addRes_24 + l_mulRes_35],
            glob->gv_promote_img0[l_addRes_25 + l_mulRes_35], glob->gv_promote_img0[l_addRes_26 + l_mulRes_35],
            glob->gv_promote_img0[l_addRes_27 + l_mulRes_35]);
        int32_t l_mulRes_37 = 70 * (l_idx_21 + 5);
        vec6 v_38 = vcons6(glob->gv_promote_img0[l_idx_20 + l_mulRes_37],
            glob->gv_promote_img0[l_addRes_23 + l_mulRes_37], glob->gv_promote_img0[l_addRes_24 + l_mulRes_37],
            glob->gv_promote_img0[l_addRes_25 + l_mulRes_37], glob->gv_promote_img0[l_addRes_26 + l_mulRes_37],
            glob->gv_promote_img0[l_addRes_27 + l_mulRes_37]);
        float l_vY__39 = v_18[1];
        vec6 v_40 = vcons6(l_vY__39 + 0.2e1f, l_vY__39 + 0.1e1f, l_vY__39, l_vY__39 - 0.1e1f, l_vY__39 - 0.2e1f,
            l_vY__39 - 0.3e1f);
        vec6 v_41 = vcons6(0.961875e1f, 0.1875e-1f, 0.8625e0f, 0.8625e0f, 0.1875e-1f, 0.961875e1f);
        vec6 v_42 = vcons6(-0.23625e2f, 0.4375e1f, 0.0f, 0.0f, -0.4375e1f, 0.23625e2f);
        vec6 v_43 = vcons6(0.2334375e2f, -0.1065625e2f, -0.14375e1f, -0.14375e1f, -0.1065625e2f, 0.2334375e2f);
        vec6 v_44 = vcons6(-0.12e2f, 0.10e2f, 0.0f, 0.0f, -0.10e2f, 0.12e2f);
        vec6 v_45 = vcons6(0.340625e1f, -0.459375e1f, 0.11875e1f, 0.11875e1f, -0.459375e1f, 0.340625e1f);
        vec6 v_46 = vcons6(-0.508333333333e0f, 0.104166666667e1f, -0.583333333333e0f, 0.583333333333e0f,
            -0.104166666667e1f, 0.508333333333e0f);
        vec6 v_47 = vcons6(0.3125e-1f, -0.9375e-1f, 0.625e-1f, 0.625e-1f, -0.9375e-1f, 0.3125e-1f);
        vec6 v_48 = v_41 + v_40 * (v_42 + v_40 * (v_43 + v_40 * (v_44 + v_40 * (v_45 + v_40 * (v_46 + v_40 * v_47)))));
        float l_vX__49 = v_18[0];
        vec6 v_50 = vcons6(l_vX__49 + 0.2e1f, l_vX__49 + 0.1e1f, l_vX__49, l_vX__49 - 0.1e1f, l_vX__49 - 0.2e1f,
            l_vX__49 - 0.3e1f);
        vec6 v_51 = v_41 + v_50 * (v_42 + v_50 * (v_43 + v_50 * (v_44 + v_50 * (v_45 + v_50 * (v_46 + v_50 * v_47)))));
        vec6 v_52 = vcons6(vdot6(v_51, v_28), vdot6(v_51, v_30), vdot6(v_51, v_32), vdot6(v_51, v_34),
            vdot6(v_51, v_36), vdot6(v_51, v_38));
        vec2 v_53 = vfloor2(v_16);
        vec2 v_54 = v_16 - v_53;
        diderot::array< int32_t, 2 > l_n_55 = vtoi2(v_53);
        int32_t l_idx_56 = l_n_55[0] + -2;
        int32_t l_idx_57 = l_n_55[1] + -2;
        int32_t l_mulRes_58 = 70 * l_idx_57;
        int32_t l_addRes_59 = l_idx_56 + 1;
        int32_t l_addRes_60 = l_idx_56 + 2;
        int32_t l_addRes_61 = l_idx_56 + 3;
        int32_t l_addRes_62 = l_idx_56 + 4;
        int32_t l_addRes_63 = l_idx_56 + 5;
        vec6 v_64 = vcons6(glob->gv_promote_img[l_idx_56 + l_mulRes_58],
            glob->gv_promote_img[l_addRes_59 + l_mulRes_58], glob->gv_promote_img[l_addRes_60 + l_mulRes_58],
            glob->gv_promote_img[l_addRes_61 + l_mulRes_58], glob->gv_promote_img[l_addRes_62 + l_mulRes_58],
            glob->gv_promote_img[l_addRes_63 + l_mulRes_58]);
        int32_t l_mulRes_65 = 70 * (l_idx_57 + 1);
        vec6 v_66 = vcons6(glob->gv_promote_img[l_idx_56 + l_mulRes_65],
            glob->gv_promote_img[l_addRes_59 + l_mulRes_65], glob->gv_promote_img[l_addRes_60 + l_mulRes_65],
            glob->gv_promote_img[l_addRes_61 + l_mulRes_65], glob->gv_promote_img[l_addRes_62 + l_mulRes_65],
            glob->gv_promote_img[l_addRes_63 + l_mulRes_65]);
        int32_t l_mulRes_67 = 70 * (l_idx_57 + 2);
        vec6 v_68 = vcons6(glob->gv_promote_img[l_idx_56 + l_mulRes_67],
            glob->gv_promote_img[l_addRes_59 + l_mulRes_67], glob->gv_promote_img[l_addRes_60 + l_mulRes_67],
            glob->gv_promote_img[l_addRes_61 + l_mulRes_67], glob->gv_promote_img[l_addRes_62 + l_mulRes_67],
            glob->gv_promote_img[l_addRes_63 + l_mulRes_67]);
        int32_t l_mulRes_69 = 70 * (l_idx_57 + 3);
        vec6 v_70 = vcons6(glob->gv_promote_img[l_idx_56 + l_mulRes_69],
            glob->gv_promote_img[l_addRes_59 + l_mulRes_69], glob->gv_promote_img[l_addRes_60 + l_mulRes_69],
            glob->gv_promote_img[l_addRes_61 + l_mulRes_69], glob->gv_promote_img[l_addRes_62 + l_mulRes_69],
            glob->gv_promote_img[l_addRes_63 + l_mulRes_69]);
        int32_t l_mulRes_71 = 70 * (l_idx_57 + 4);
        vec6 v_72 = vcons6(glob->gv_promote_img[l_idx_56 + l_mulRes_71],
            glob->gv_promote_img[l_addRes_59 + l_mulRes_71], glob->gv_promote_img[l_addRes_60 + l_mulRes_71],
            glob->gv_promote_img[l_addRes_61 + l_mulRes_71], glob->gv_promote_img[l_addRes_62 + l_mulRes_71],
            glob->gv_promote_img[l_addRes_63 + l_mulRes_71]);
        int32_t l_mulRes_73 = 70 * (l_idx_57 + 5);
        vec6 v_74 = vcons6(glob->gv_promote_img[l_idx_56 + l_mulRes_73],
            glob->gv_promote_img[l_addRes_59 + l_mulRes_73], glob->gv_promote_img[l_addRes_60 + l_mulRes_73],
            glob->gv_promote_img[l_addRes_61 + l_mulRes_73], glob->gv_promote_img[l_addRes_62 + l_mulRes_73],
            glob->gv_promote_img[l_addRes_63 + l_mulRes_73]);
        float l_vY__75 = v_54[1];
        vec6 v_76 = vcons6(l_vY__75 + 0.2e1f, l_vY__75 + 0.1e1f, l_vY__75, l_vY__75 - 0.1e1f, l_vY__75 - 0.2e1f,
            l_vY__75 - 0.3e1f);
        vec6 v_77 = v_41 + v_76 * (v_42 + v_76 * (v_43 + v_76 * (v_44 + v_76 * (v_45 + v_76 * (v_46 + v_76 * v_47)))));
        float l_vX__78 = v_54[0];
        vec6 v_79 = vcons6(l_vX__78 + 0.2e1f, l_vX__78 + 0.1e1f, l_vX__78, l_vX__78 - 0.1e1f, l_vX__78 - 0.2e1f,
            l_vX__78 - 0.3e1f);
        vec6 v_80 = v_41 + v_79 * (v_42 + v_79 * (v_43 + v_79 * (v_44 + v_79 * (v_45 + v_79 * (v_46 + v_79 * v_47)))));
        vec6 v_81 = vcons6(vdot6(v_80, v_64), vdot6(v_80, v_66), vdot6(v_80, v_68), vdot6(v_80, v_70),
            vdot6(v_80, v_72), vdot6(v_80, v_74));
        vec6 v_82 = vcons6(0.466875e2f, -0.213125e2f, -0.2875e1f, -0.2875e1f, -0.213125e2f, 0.466875e2f);
        vec6 v_83 = vcons6(-0.36e2f, 0.30e2f, 0.0f, 0.0f, -0.30e2f, 0.36e2f);
        vec6 v_84 = vcons6(0.13625e2f, -0.18375e2f, 0.475e1f, 0.475e1f, -0.18375e2f, 0.13625e2f);
        vec6 v_85 = vcons6(-0.254166666667e1f, 0.520833333333e1f, -0.291666666667e1f, 0.291666666667e1f,
            -0.520833333333e1f, 0.254166666667e1f);
        vec6 v_86 = vcons6(0.1875e0f, -0.5625e0f, 0.375e0f, 0.375e0f, -0.5625e0f, 0.1875e0f);
        vec6 v_87 = v_42 + v_50 * (v_82 + v_50 * (v_83 + v_50 * (v_84 + v_50 * (v_85 + v_50 * v_86))));
        vec2 v_88 = vcons2(
            vdot6(v_48,
                vcons6(vdot6(v_87, v_28), vdot6(v_87, v_30), vdot6(v_87, v_32), vdot6(v_87, v_34), vdot6(v_87, v_36),
                    vdot6(v_87, v_38))),
            vdot6(v_42 + v_40 * (v_82 + v_40 * (v_83 + v_40 * (v_84 + v_40 * (v_85 + v_40 * v_86)))), v_52));
        vec6 v_89 = v_42 + v_79 * (v_82 + v_79 * (v_83 + v_79 * (v_84 + v_79 * (v_85 + v_79 * v_86))));
        vec2 v_90 = vcons2(
            vdot6(v_77,
                vcons6(vdot6(v_89, v_64), vdot6(v_89, v_66), vdot6(v_89, v_68), vdot6(v_89, v_70), vdot6(v_89, v_72),
                    vdot6(v_89, v_74))),
            vdot6(v_42 + v_76 * (v_82 + v_76 * (v_83 + v_76 * (v_84 + v_76 * (v_85 + v_76 * v_86)))), v_81));
        bool l_r_91 = vdot6(v_48, v_52) > vdot6(v_77, v_81);
        v_92 = vcons2(
            IfWrap(l_r_91, vdot2(v_88, vcons2(l_Mtransform_11[0], l_Mtransform_11[2])),
                vdot2(v_90, vcons2(l_Mtransform_13[0], l_Mtransform_13[2]))),
            IfWrap(l_r_91, vdot2(v_88, vcons2(l_Mtransform_11[1], l_Mtransform_11[3])),
                vdot2(v_90, vcons2(l_Mtransform_13[1], l_Mtransform_13[3]))));
    }
    else {
        v_92 = vload2(tensor_ref_2(self->sv_out).addr(0));
    }
    vpack2(self->sv_pos, v_6);
    vpack2(self->sv_out, v_92);
    return diderot::kStabilize;
}
bool output_get_out (world *wrld, Nrrd *nData)
{
    // Compute sizes of nrrd file
    size_t sizes[2];
    sizes[0] = 2;
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
        memcpy(cp, &wrld->_strands.strand(ix)->sv_out, 2 * sizeof(float));
        cp += 2 * sizeof(float);
    }
    nData->axis[0].kind = nrrdKind2Vector;
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
    for (int i_i_95 = lo_0; i_i_95 <= hi_1; i_i_95++) {
        sample_init(this->_strands.strand(ix), i_i_95);
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

