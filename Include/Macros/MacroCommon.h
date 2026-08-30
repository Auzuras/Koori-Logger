#ifndef KOORI_LOGGER_LOG_MACRO_COMMON_H
#define KOORI_LOGGER_LOG_MACRO_COMMON_H

/**
 * @brief __KOORI_COMBINE Combine macro
 *
 * @param _x Combine the parameters value
 */
#define __KOORI_COMBINE(_x) _x

/**
 * @brief __KOORI_VARIADIC_FOUR_PARAMS Macro, selects the correct macro according to the number of arguments
 *
 * @param _1 First variadic parameter
 * @param _2 Second variadic parameter
 * @param _3 Third variadic parameter
 * @param _4 Fourth variadic parameter
 * @param _name Name of the selected macro
 * @param ... Other parameters
 */
#define __KOORI_VARIADIC_FOUR_PARAMS(_1, _2, _3, _4, _name, ...) _name

/**
 * @brief __KOORI_VARIADIC_THREE_PARAMS Macro, selects the correct macro according to the number of arguments
 *
 * @param _1 First variadic parameter
 * @param _2 Second variadic parameter
 * @param _3 Third variadic parameter
 * @param _name Name of the selected macro
 * @param ... Other parameters
 */
#define __KOORI_VARIADIC_THREE_PARAMS(_1, _2, _3, _name, ...) _name

/**
 * @brief __KOORI_VARIADIC_TWO_PARAMS Macro, selects the correct macro according to the number of arguments
 *
 * @param _1 First variadic parameter
 * @param _2 Second variadic parameter
 * @param _name Name of the selected macro
 * @param ... Other parameters
 */
#define __KOORI_VARIADIC_TWO_PARAMS(_1, _2, _name, ...) _name

#endif //KOORI_LOGGER_LOG_MACRO_COMMON_H