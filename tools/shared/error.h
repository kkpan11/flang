/*
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 */

/** \file
 * \brief Compiler Error handling and reporting.
 */

#ifndef COMPILER_ERROR_H_
#define COMPILER_ERROR_H_

#include "gbldefs.h"
/* Get the error_code enum which is generated by the errmsg util. */
#include "errmsgdf.h"

/* The rest of error definitions */
#include "flang/Error/pgerror.h"

/**
 * \brief Convert an integer to a string, for printing numbers in error
 * messages.
 *
 * This returns a pointer to static data, so only use it once.
 */
char *errnum(int num);

/**
   \brief ...
 */
enum error_severity error_max_severity(void);

/** Write either error summary message for current subprogram unit, or final
 * execution summary line to user's terminal. Return the maximum error severity
 * seen for the entire file.
 */
int summary(bool final, int ipafollows);

/**
  * Prints information on behalf of failed asrt.
  * \param file: filename: name of file where assertion failed.
  * \param line: line number where assertion failed
  */
void asrt_failed(const char *filename, int line);

/**
 * Prints information on behalf of failed DEBUG_ASSERT.
 * \param filename name of file where assertion failed.
 * \param line     line number where assertion failed.
 * \param expr     string representation of assertion that failed.
 * \param txt      optional text to print via interr. Use NULL if no text
 */
void dassert_err(const char *filename, int line, const char *expr,
                 const char *txt);

/// \brief Set the emit error flag(s)
void erremit(int x);

/// \brief Issue a fatal error for gbl.lineno.
void errfatal(error_code_t ecode);

/// \brief Issue an informational message for gbl.lineno.
void errinfo(error_code_t ecode);

/// \brief Initialize error counts for new user subprogram
void errini(void);

/** 
    \brief Massage label name if necesseary.
    \param ecode  error number
    \param sev    error severity in range 1 ... 4
    \param eline  source file line number
    \param nm     label name
    \param op2    extra string
 */
void errlabel(error_code_t ecode, enum error_severity sev, int eline, char *nm,
              const char *op2);

/** 
 * \brief Construct and issue an error message.
 * \param ecode  error number
 * \param sev    error severity (a value in the err_severity enum)
 * \param eline  source file line number
 * \param op1    string to be expanded into error message * or 0
 * \param op2    string to be expanded into error message * or 0
 *
 * Construct error message and issue it to user terminal and to listing file
 * if appropriate.
 */
void error(error_code_t ecode, enum error_severity sev, int eline,
           const char *op1, const char *op2);

/// \brief Issue a severe error message for gbl.lineno.
void errsev(error_code_t ecode);

/// \brief Print version info
void errversion(void);

/// \brief Issue a warning for gbl.lineno.
void errwarn(error_code_t ecode);

/// \brief Floating point error
void fperror(int errcode);

/**
 * \brief Issue internal compiler error.
 * \param txt  null terminated text string identifying
 * \param val  integer value to be written with message
 * \param sev  error severity
 */
void interr(const char *txt, int val, enum error_severity sev);

/** \brief Issue internal compiler error using printf-style formatting.
 *
 * \param sev:   error severity.
 * \param fmt:   printf-style format string
 * \param ...:   args for format string
 */
void interrf(enum error_severity sev, const char *fmt, ...);

#endif /* COMPILER_ERROR_H_ */
