/*---------- begin exec-head.in ----------*/
/*! \file max.cxx
 *
 * Generated from max.diderot.
 *
 * Command: /Users/chariseechiw/diderot/chiw17/bin/diderotc --exec max.diderot
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

static std::string ProgramName = "max";

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
    float sv_out;
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
    bool alloc (int32_t base[2], uint32_t size[2]);
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
    if (l_promote_img0_0.load(wrld, "../../data/const8.nrrd")) {
        return true;
    }
    glob->gv_promote_img0 = l_promote_img0_0;
    if (l_promote_img_1.load(wrld, "../../data/const1.nrrd")) {
        return true;
    }
    glob->gv_promote_img = l_promote_img_1;
    glob->gv_outSize = 10;
    return false;
}
static void sample_init (sample_strand *self, int32_t p_ui_2, int32_t p_vi_3)
{
    self->sv_pos[0] = static_cast<float>(p_ui_2);
    self->sv_pos[1] = static_cast<float>(p_vi_3);
    self->sv_out = -0.77e2f;
}
static diderot::strand_status sample_update (globals *glob, sample_strand *self)
{
    float l_out_60;
    tensor_ref_2_2 l_Mtransform_5 = world2image(glob->gv_promote_img0);
    vec2 v_6 = vcons2(vdot2(vload2(l_Mtransform_5.last(0).addr(0)), vload2(tensor_ref_2(self->sv_pos).addr(0))),
        vdot2(vload2(l_Mtransform_5.last(2).addr(0)), vload2(tensor_ref_2(self->sv_pos).addr(0)))) + vload2(
        translate(glob->gv_promote_img0).addr(0));
    tensor_ref_2_2 l_Mtransform_7 = world2image(glob->gv_promote_img);
    vec2 v_8 = vcons2(vdot2(vload2(l_Mtransform_7.last(0).addr(0)), vload2(tensor_ref_2(self->sv_pos).addr(0))),
        vdot2(vload2(l_Mtransform_7.last(2).addr(0)), vload2(tensor_ref_2(self->sv_pos).addr(0)))) + vload2(
        translate(glob->gv_promote_img).addr(0));
    vec2 v_9 = v_8;
    vec2 v_10 = v_6;
    if (inside2Ds3(v_6, glob->gv_promote_img0) && inside2Ds3(v_8, glob->gv_promote_img)) {
        vec2 v_11 = vfloor2(v_10);
        vec2 v_12 = v_10 - v_11;
        diderot::array< int32_t, 2 > l_n_13 = vtoi2(v_11);
        int32_t l_idx_14 = l_n_13[0] + -2;
        int32_t l_idx_15 = l_n_13[1] + -2;
        int32_t l_mulRes_16 = 101 * l_idx_15;
        int32_t l_addRes_17 = l_idx_14 + 1;
        int32_t l_addRes_18 = l_idx_14 + 2;
        int32_t l_addRes_19 = l_idx_14 + 3;
        int32_t l_addRes_20 = l_idx_14 + 4;
        int32_t l_addRes_21 = l_idx_14 + 5;
        int32_t l_mulRes_22 = 101 * (l_idx_15 + 1);
        int32_t l_mulRes_23 = 101 * (l_idx_15 + 2);
        int32_t l_mulRes_24 = 101 * (l_idx_15 + 3);
        int32_t l_mulRes_25 = 101 * (l_idx_15 + 4);
        int32_t l_mulRes_26 = 101 * (l_idx_15 + 5);
        float l_vY__27 = v_12[1];
        vec6 v_28 = vcons6(l_vY__27 + 0.2e1f, l_vY__27 + 0.1e1f, l_vY__27, l_vY__27 - 0.1e1f, l_vY__27 - 0.2e1f,
            l_vY__27 - 0.3e1f);
        vec6 v_29 = vcons6(0.961875e1f, 0.1875e-1f, 0.8625e0f, 0.8625e0f, 0.1875e-1f, 0.961875e1f);
        vec6 v_30 = vcons6(-0.23625e2f, 0.4375e1f, 0.0f, 0.0f, -0.4375e1f, 0.23625e2f);
        vec6 v_31 = vcons6(0.2334375e2f, -0.1065625e2f, -0.14375e1f, -0.14375e1f, -0.1065625e2f, 0.2334375e2f);
        vec6 v_32 = vcons6(-0.12e2f, 0.10e2f, 0.0f, 0.0f, -0.10e2f, 0.12e2f);
        vec6 v_33 = vcons6(0.340625e1f, -0.459375e1f, 0.11875e1f, 0.11875e1f, -0.459375e1f, 0.340625e1f);
        vec6 v_34 = vcons6(-0.508333333333e0f, 0.104166666667e1f, -0.583333333333e0f, 0.583333333333e0f,
            -0.104166666667e1f, 0.508333333333e0f);
        vec6 v_35 = vcons6(0.3125e-1f, -0.9375e-1f, 0.625e-1f, 0.625e-1f, -0.9375e-1f, 0.3125e-1f);
        float l_vX__36 = v_12[0];
        vec6 v_37 = vcons6(l_vX__36 + 0.2e1f, l_vX__36 + 0.1e1f, l_vX__36, l_vX__36 - 0.1e1f, l_vX__36 - 0.2e1f,
            l_vX__36 - 0.3e1f);
        vec6 v_38 = v_29 + v_37 * (v_30 + v_37 * (v_31 + v_37 * (v_32 + v_37 * (v_33 + v_37 * (v_34 + v_37 * v_35)))));
        vec2 v_39 = vfloor2(v_9);
        vec2 v_40 = v_9 - v_39;
        diderot::array< int32_t, 2 > l_n_41 = vtoi2(v_39);
        int32_t l_idx_42 = l_n_41[0] + -2;
        int32_t l_idx_43 = l_n_41[1] + -2;
        int32_t l_mulRes_44 = 101 * l_idx_43;
        int32_t l_addRes_45 = l_idx_42 + 1;
        int32_t l_addRes_46 = l_idx_42 + 2;
        int32_t l_addRes_47 = l_idx_42 + 3;
        int32_t l_addRes_48 = l_idx_42 + 4;
        int32_t l_addRes_49 = l_idx_42 + 5;
        int32_t l_mulRes_50 = 101 * (l_idx_43 + 1);
        int32_t l_mulRes_51 = 101 * (l_idx_43 + 2);
        int32_t l_mulRes_52 = 101 * (l_idx_43 + 3);
        int32_t l_mulRes_53 = 101 * (l_idx_43 + 4);
        int32_t l_mulRes_54 = 101 * (l_idx_43 + 5);
        float l_vY__55 = v_40[1];
        vec6 v_56 = vcons6(l_vY__55 + 0.2e1f, l_vY__55 + 0.1e1f, l_vY__55, l_vY__55 - 0.1e1f, l_vY__55 - 0.2e1f,
            l_vY__55 - 0.3e1f);
        float l_vX__57 = v_40[0];
        vec6 v_58 = vcons6(l_vX__57 + 0.2e1f, l_vX__57 + 0.1e1f, l_vX__57, l_vX__57 - 0.1e1f, l_vX__57 - 0.2e1f,
            l_vX__57 - 0.3e1f);
        vec6 v_59 = v_29 + v_58 * (v_30 + v_58 * (v_31 + v_58 * (v_32 + v_58 * (v_33 + v_58 * (v_34 + v_58 * v_35)))));
        l_out_60 = std::min(
            vdot6(v_29 + v_28 * (v_30 + v_28 * (v_31 + v_28 * (v_32 + v_28 * (v_33 + v_28 * (v_34 + v_28 * v_35))))),
                vcons6(
                    vdot6(v_38,
                        vcons6(glob->gv_promote_img0[l_idx_14 + l_mulRes_16],
                            glob->gv_promote_img0[l_addRes_17 + l_mulRes_16],
                            glob->gv_promote_img0[l_addRes_18 + l_mulRes_16],
                            glob->gv_promote_img0[l_addRes_19 + l_mulRes_16],
                            glob->gv_promote_img0[l_addRes_20 + l_mulRes_16],
                            glob->gv_promote_img0[l_addRes_21 + l_mulRes_16])),
                    vdot6(v_38,
                        vcons6(glob->gv_promote_img0[l_idx_14 + l_mulRes_22],
                            glob->gv_promote_img0[l_addRes_17 + l_mulRes_22],
                            glob->gv_promote_img0[l_addRes_18 + l_mulRes_22],
                            glob->gv_promote_img0[l_addRes_19 + l_mulRes_22],
                            glob->gv_promote_img0[l_addRes_20 + l_mulRes_22],
                            glob->gv_promote_img0[l_addRes_21 + l_mulRes_22])),
                    vdot6(v_38,
                        vcons6(glob->gv_promote_img0[l_idx_14 + l_mulRes_23],
                            glob->gv_promote_img0[l_addRes_17 + l_mulRes_23],
                            glob->gv_promote_img0[l_addRes_18 + l_mulRes_23],
                            glob->gv_promote_img0[l_addRes_19 + l_mulRes_23],
                            glob->gv_promote_img0[l_addRes_20 + l_mulRes_23],
                            glob->gv_promote_img0[l_addRes_21 + l_mulRes_23])),
                    vdot6(v_38,
                        vcons6(glob->gv_promote_img0[l_idx_14 + l_mulRes_24],
                            glob->gv_promote_img0[l_addRes_17 + l_mulRes_24],
                            glob->gv_promote_img0[l_addRes_18 + l_mulRes_24],
                            glob->gv_promote_img0[l_addRes_19 + l_mulRes_24],
                            glob->gv_promote_img0[l_addRes_20 + l_mulRes_24],
                            glob->gv_promote_img0[l_addRes_21 + l_mulRes_24])),
                    vdot6(v_38,
                        vcons6(glob->gv_promote_img0[l_idx_14 + l_mulRes_25],
                            glob->gv_promote_img0[l_addRes_17 + l_mulRes_25],
                            glob->gv_promote_img0[l_addRes_18 + l_mulRes_25],
                            glob->gv_promote_img0[l_addRes_19 + l_mulRes_25],
                            glob->gv_promote_img0[l_addRes_20 + l_mulRes_25],
                            glob->gv_promote_img0[l_addRes_21 + l_mulRes_25])),
                    vdot6(v_38,
                        vcons6(glob->gv_promote_img0[l_idx_14 + l_mulRes_26],
                            glob->gv_promote_img0[l_addRes_17 + l_mulRes_26],
                            glob->gv_promote_img0[l_addRes_18 + l_mulRes_26],
                            glob->gv_promote_img0[l_addRes_19 + l_mulRes_26],
                            glob->gv_promote_img0[l_addRes_20 + l_mulRes_26],
                            glob->gv_promote_img0[l_addRes_21 + l_mulRes_26])))),
            vdot6(v_29 + v_56 * (v_30 + v_56 * (v_31 + v_56 * (v_32 + v_56 * (v_33 + v_56 * (v_34 + v_56 * v_35))))),
                vcons6(
                    vdot6(v_59,
                        vcons6(glob->gv_promote_img[l_idx_42 + l_mulRes_44],
                            glob->gv_promote_img[l_addRes_45 + l_mulRes_44],
                            glob->gv_promote_img[l_addRes_46 + l_mulRes_44],
                            glob->gv_promote_img[l_addRes_47 + l_mulRes_44],
                            glob->gv_promote_img[l_addRes_48 + l_mulRes_44],
                            glob->gv_promote_img[l_addRes_49 + l_mulRes_44])),
                    vdot6(v_59,
                        vcons6(glob->gv_promote_img[l_idx_42 + l_mulRes_50],
                            glob->gv_promote_img[l_addRes_45 + l_mulRes_50],
                            glob->gv_promote_img[l_addRes_46 + l_mulRes_50],
                            glob->gv_promote_img[l_addRes_47 + l_mulRes_50],
                            glob->gv_promote_img[l_addRes_48 + l_mulRes_50],
                            glob->gv_promote_img[l_addRes_49 + l_mulRes_50])),
                    vdot6(v_59,
                        vcons6(glob->gv_promote_img[l_idx_42 + l_mulRes_51],
                            glob->gv_promote_img[l_addRes_45 + l_mulRes_51],
                            glob->gv_promote_img[l_addRes_46 + l_mulRes_51],
                            glob->gv_promote_img[l_addRes_47 + l_mulRes_51],
                            glob->gv_promote_img[l_addRes_48 + l_mulRes_51],
                            glob->gv_promote_img[l_addRes_49 + l_mulRes_51])),
                    vdot6(v_59,
                        vcons6(glob->gv_promote_img[l_idx_42 + l_mulRes_52],
                            glob->gv_promote_img[l_addRes_45 + l_mulRes_52],
                            glob->gv_promote_img[l_addRes_46 + l_mulRes_52],
                            glob->gv_promote_img[l_addRes_47 + l_mulRes_52],
                            glob->gv_promote_img[l_addRes_48 + l_mulRes_52],
                            glob->gv_promote_img[l_addRes_49 + l_mulRes_52])),
                    vdot6(v_59,
                        vcons6(glob->gv_promote_img[l_idx_42 + l_mulRes_53],
                            glob->gv_promote_img[l_addRes_45 + l_mulRes_53],
                            glob->gv_promote_img[l_addRes_46 + l_mulRes_53],
                            glob->gv_promote_img[l_addRes_47 + l_mulRes_53],
                            glob->gv_promote_img[l_addRes_48 + l_mulRes_53],
                            glob->gv_promote_img[l_addRes_49 + l_mulRes_53])),
                    vdot6(v_59,
                        vcons6(glob->gv_promote_img[l_idx_42 + l_mulRes_54],
                            glob->gv_promote_img[l_addRes_45 + l_mulRes_54],
                            glob->gv_promote_img[l_addRes_46 + l_mulRes_54],
                            glob->gv_promote_img[l_addRes_47 + l_mulRes_54],
                            glob->gv_promote_img[l_addRes_48 + l_mulRes_54],
                            glob->gv_promote_img[l_addRes_49 + l_mulRes_54])))));
    }
    else {
        l_out_60 = self->sv_out;
    }
    self->sv_out = l_out_60;
    return diderot::kStabilize;
}
bool output_get_out (world *wrld, Nrrd *nData)
{
    // Compute sizes of nrrd file
    size_t sizes[2];
    sizes[0] = wrld->_size[1];
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
        memcpy(cp, &wrld->_strands.strand(ix)->sv_out, 1 * sizeof(float));
        cp += 1 * sizeof(float);
    }
    nData->axis[0].kind = nrrdKindSpace;
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
    : diderot::world_base (ProgramName, true, 2)
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
bool world::alloc (int32_t base[2], uint32_t size[2])
{
    size_t numStrands = 1;
    for (uint32_t i = 0;  i < 2;  i++) {
        numStrands *= size[i];
        this->_base[i] = base[i];
        this->_size[i] = size[i];
    }

    if (this->_verbose) {
        std::cerr << "world::alloc: " << size[0];
        for (uint32_t i = 1;  i < 2;  i++) {
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
    int32_t l__t_61 = glob->gv_outSize - 1;
    int lo_0 = 0;
    int lo_1 = 0;
    int32_t base[2] = {lo_0,lo_1,};
    uint32_t size[2] = {static_cast<uint32_t>(l__t_61 - lo_0 + 1),static_cast<uint32_t>(l__t_61 - lo_1 + 1),};
    if (this->alloc(base, size)) {
        return true;
    }
    uint32_t ix = 0;
    for (int i_vi_62 = lo_0; i_vi_62 <= l__t_61; i_vi_62++) {
        for (int i_ui_63 = lo_1; i_ui_63 <= l__t_61; i_ui_63++) {
            sample_init(this->_strands.strand(ix), i_ui_63, i_vi_62);
            ++ix;
        }
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

