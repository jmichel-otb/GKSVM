#ifndef _LIBGKSVM_H
#define _LIBGKSVM_H

#define LIBGKSVM_VERSION 300

/*** Begin OTB modification ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <map>
#include <string>
#include <utility>
#include <vector>


struct gksvm_node;
struct gksvm_parameter;

/** \class GenericKernelFunctorBase
 * \brief Undocumented
 *
 * \ingroup OTBLibSVM
 */
class GenericKernelFunctorBase
{
public:
  typedef GenericKernelFunctorBase Self;

  typedef std::map<std::string, std::string> MapType;
  typedef MapType::iterator MapIterator;
  typedef MapType::const_iterator MapConstIterator;

  GenericKernelFunctorBase();

  virtual ~GenericKernelFunctorBase();

  virtual GenericKernelFunctorBase* Clone() const;

  virtual double operator()(const gksvm_node * /*x*/, const gksvm_node * /*y*/, const gksvm_parameter& /*param*/) const;


  virtual double derivative(const gksvm_node * /*x*/, const gksvm_node * /*y*/, const gksvm_parameter& /*param*/,
                            int /*degree*/, int /*index*/, bool /*isAtEnd*/, double /*constValue*/) const;

  virtual int load_parameters(FILE ** pfile);

  virtual int save_parameters(FILE ** pfile, const char * generic_kernel_parameters_keyword) const;

  virtual void print_parameters(void) const;

  virtual double dot(const gksvm_node *px, const gksvm_node *py) const;

  virtual gksvm_node * sub(const gksvm_node *px, const gksvm_node *py) const;

  virtual gksvm_node * add(const gksvm_node *px, const gksvm_node *py) const;

  virtual void SetName(std::string name);
  virtual std::string GetName(void) const;

  virtual void SetMapParameters(const MapType & map);
  virtual const MapType & GetMapParameters() const;
  virtual MapType GetMapParameters();

  template<class T>
  T GetValue(const char *option) const
  {
    std::string Value = m_MapParameters.find(std::string(option))->second;
    T lValeur;
    std::stringstream flux;
    flux << Value;
    flux >> lValeur;
    return lValeur;
  }

  template<class T>
  void SetValue(const char *option, const T & value)
  {
    std::string lValeur;
    std::stringstream flux;
    flux << value;
    flux >> lValeur;
    m_MapParameters[std::string(option)] = lValeur;
  }

  // Override this method to to split m_MapParameters into specific variables to speed up kernel evaluations
  virtual void Update(void);

protected:
  GenericKernelFunctorBase(const Self& copy);

  Self& operator=(const Self& copy);

private:
  /** Kernel functor parameters */
  MapType m_MapParameters;

  /** Functor label name (without space) */
  std::string m_Name;
};

/** \class ComposedKernelFunctor
 * \brief Undocumented
 *
 * \ingroup OTBLibSVM
 */
class ComposedKernelFunctor: public GenericKernelFunctorBase
{
public:
  typedef ComposedKernelFunctor    Self;
  typedef GenericKernelFunctorBase Superclass;

  ComposedKernelFunctor();

  virtual ~ComposedKernelFunctor();

  virtual ComposedKernelFunctor* Clone() const;

  typedef std::vector<GenericKernelFunctorBase *> KernelListType;

  virtual double operator()(const gksvm_node *x, const gksvm_node *y, const gksvm_parameter& param) const;

  /** Used for Taylor classification*/
  // degree is the developement degree
  // index is the current value
  // isAtEnd to indicate that it's the last possible derivation
  // baseValue is the constant of the formula
  virtual double derivative(const gksvm_node *x, const gksvm_node *y, const gksvm_parameter& param, int degree, int index, bool isAtEnd, double constValue) const;

  virtual int load_parameters(FILE ** pfile);

  virtual int save_parameters(FILE ** pfile, const char * composed_kernel_parameters_keyword) const;

  virtual void print_parameters(void)const;

  /** Get a reference to the internal kernel list */
  KernelListType& GetKernelFunctorList();

  /** Set internal kernel list. A clone is made of each kernel when copying */
  void SetKernelFunctorList(const KernelListType& kernelFunctorList);

  // Add 1 element to the end of the list. A clone is made of the kernel
  void AddKernelFunctorModelToKernelList(const GenericKernelFunctorBase * kernelfunctor);

  /** Set/Get the ponderation list to apply to each gksvm_model of the composed kernel */
  std::vector<double> GetPonderationList();
  void SetPonderationModelList(const std::vector<double> & list);
  // Add 1 element to the end of the list
  void AddPonderationToPonderationList(const double & pond);

  /** Set/Get the boolean to know which operation has to be done with the kernel functors. */
  void SetMultiplyKernelFunctor( bool val );
  bool GetMultiplyKernelFunctor();

protected:
  /** Copy constructor */
  ComposedKernelFunctor(const Self& copy);

  /* Assignment operator */
  Self& operator=(const Self& copy);

private:

  void ClearFunctorList();

  typedef GenericKernelFunctorBase::MapType MapType;
  typedef GenericKernelFunctorBase::MapIterator MapIterator;
  typedef GenericKernelFunctorBase::MapConstIterator MapConstIterator;

  /** Generic kernel functors that composed kernel */
  KernelListType m_KernelFunctorList;
  /** Ponderation list to apply to each gksvm_model of the composed kernel*/
  std::vector<double> m_PonderationList;
};

//#ifdef __cplusplus
//extern "C" {
//#endif
/*** End OTB modification ***/

extern int libgksvm_version;

struct gksvm_node
{
	int index;
	double value;
};

struct gksvm_problem
{
	int l;
	double *y;
	struct gksvm_node **x;
};

enum { C_SVC, NU_SVC, ONE_CLASS, EPSILON_SVR, NU_SVR };	/* gksvm_type */
enum { LINEAR, POLY, RBF, SIGMOID, PRECOMPUTED, GENERIC, COMPOSED }; /* kernel_type */

struct gksvm_parameter
{
  /*** Begin OTB modification ***/
  gksvm_parameter()
  : kernel_generic(NULL),
    kernel_composed(NULL),
    nr_weight(0),
    weight_label(NULL),
    weight(NULL)
  {
  }

  gksvm_parameter(const gksvm_parameter& copy)
  : kernel_generic(NULL),
    kernel_composed(NULL),
    nr_weight(0),
    weight_label(NULL),
    weight(NULL)
  {
    *this = copy;
  }

  ~gksvm_parameter()
  {
    delete kernel_generic;
    delete kernel_composed;
    free(weight_label);
    free(weight);
  }

  gksvm_parameter& operator=(const gksvm_parameter& copy)
  {
    gksvm_type = copy.gksvm_type;
    kernel_type = copy.kernel_type;
    degree = copy.degree;
    gamma = copy.gamma;
    coef0 = copy.coef0;
    const_coef = copy.const_coef;
    lin_coef = copy.lin_coef;
    memcpy(custom, copy.custom, 500);
    delete kernel_generic;
    delete kernel_composed;
    kernel_generic = copy.kernel_generic != NULL ? copy.kernel_generic->Clone() : NULL;
    kernel_composed = copy.kernel_composed != NULL ? copy.kernel_composed->Clone() : NULL;
    cache_size = copy.cache_size;
    eps = copy.eps;
    C = copy.C;

    if (nr_weight > 0)
      {
      free(weight_label);
      free(weight);
      }

    nr_weight = copy.nr_weight;
    if (nr_weight > 0)
      {
      weight_label = (int *)malloc(nr_weight*sizeof(int));
      weight = (double *)malloc(nr_weight*sizeof(double));
      }
    else
      {
      weight_label = NULL;
      weight = NULL;
      }
    memcpy(weight_label, copy.weight_label, nr_weight);
    memcpy(weight, copy.weight, nr_weight);
    nu = copy.nu;
    p = copy.p;
    shrinking = copy.shrinking;
    probability = copy.probability;
    return *this;
  }
  /*** End OTB modification ***/

  int gksvm_type;
	int kernel_type;
	int degree;	/* for poly */
	double gamma;	/* for poly/rbf/sigmoid */
	double coef0;	/* for poly/sigmoid */

	/*** Begin OTB modification ***/
  double const_coef;
  double lin_coef;
  char custom[500];
  GenericKernelFunctorBase * kernel_generic;
  ComposedKernelFunctor * kernel_composed;
  /*** End OTB modification ***/

	/* these are for training only */
	double cache_size; /* in MB */
	double eps;	/* stopping criteria */
	double C;	/* for C_SVC, EPSILON_SVR and NU_SVR */
	int nr_weight;		/* for C_SVC */
	int *weight_label;	/* for C_SVC */
	double* weight;		/* for C_SVC */
	double nu;	/* for NU_SVC, ONE_CLASS, and NU_SVR */
	double p;	/* for EPSILON_SVR */
	int shrinking;	/* use the shrinking heuristics */
	int probability; /* do probability estimates */
};

//
// gksvm_model
//
struct gksvm_model
{
	struct gksvm_parameter param;	/* parameter */
	int nr_class;		/* number of classes, = 2 in regression/one class svm */
	int l;			/* total #SV */
	struct gksvm_node **SV;		/* SVs (SV[l]) */
	double **sv_coef;	/* coefficients for SVs in decision functions (sv_coef[k-1][l]) */
	double *rho;		/* constants in decision functions (rho[k*(k-1)/2]) */
	double *probA;		/* pariwise probability information */
	double *probB;

	/* for classification only */

	int *label;		/* label of each class (label[k]) */
	int *nSV;		/* number of SVs for each class (nSV[k]) */
				/* nSV[0] + nSV[1] + ... + nSV[k-1] = l */
	/* XXX */
	int free_sv;		/* 1 if gksvm_model is created by gksvm_load_model*/
				/* 0 if gksvm_model is created by gksvm_train */
};

struct gksvm_model *gksvm_train(const struct gksvm_problem *prob, const struct gksvm_parameter *param);
void gksvm_cross_validation(const struct gksvm_problem *prob, const struct gksvm_parameter *param, int nr_fold, double *target);

int gksvm_save_model(const char *model_file_name, const struct gksvm_model *model);
/*** Begin OTB modification ***/
struct gksvm_model *gksvm_load_model(const char *model_file_name, GenericKernelFunctorBase* generic_kernel_functor = NULL);
struct gksvm_model *gksvm_copy_model( const gksvm_model *model );
/*** End OTB modification ***/

int gksvm_get_gksvm_type(const struct gksvm_model *model);
int gksvm_get_nr_class(const struct gksvm_model *model);
void gksvm_get_labels(const struct gksvm_model *model, int *label);
double gksvm_get_svr_probability(const struct gksvm_model *model);

double gksvm_predict_values(const struct gksvm_model *model, const struct gksvm_node *x, double* dec_values);
double gksvm_predict(const struct gksvm_model *model, const struct gksvm_node *x);
double gksvm_predict_probability(const struct gksvm_model *model, const struct gksvm_node *x, double* prob_estimates);

void gksvm_free_model_content(struct gksvm_model *model_ptr);
void gksvm_free_and_destroy_model(struct gksvm_model **model_ptr_ptr);
void gksvm_destroy_param(struct gksvm_parameter *param);

const char *gksvm_check_parameter(const struct gksvm_problem *prob, const struct gksvm_parameter *param);
int gksvm_check_probability_model(const struct gksvm_model *model);

void gksvm_set_print_string_function(void (*print_func)(const char *));

// deprecated
// this function will be removed in future release
void gksvm_destroy_model(struct gksvm_model *model_ptr);

/*** Begin OTB modification ***/
//#ifdef __cplusplus
//}
//#endif
/*** End OTB modification ***/

#endif /* _LIBGKSVM_H */
