#include "sai_redis.h"

/**
 * Routine Description:
 *    @brief Create next hop
 *
 * Arguments:
 *    @param[out] next_hop_id - next hop id
 *    @param[in] attr_count - number of attributes
 *    @param[in] attr_list - array of attributes
 *
 * Return Values:
 *    @return SAI_STATUS_SUCCESS on success
 *            Failure status code on error
 *
 * Note: IP address expected in Network Byte Order.
 */
sai_status_t redis_create_next_hop(
        _Out_ sai_object_id_t* next_hop_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list)
{
    std::lock_guard<std::mutex> lock(g_apimutex);

    SWSS_LOG_ENTER();

    return meta_sai_create_oid(
            SAI_OBJECT_TYPE_NEXT_HOP,
            next_hop_id,
            attr_count,
            attr_list,
            &redis_generic_create);
}

/**
 * Routine Description:
 *    @brief Remove next hop
 *
 * Arguments:
 *    @param[in] next_hop_id - next hop id
 *
 * Return Values:
 *    @return SAI_STATUS_SUCCESS on success
 *            Failure status code on error
 */
sai_status_t redis_remove_next_hop(
        _In_ sai_object_id_t next_hop_id)
{
    std::lock_guard<std::mutex> lock(g_apimutex);

    SWSS_LOG_ENTER();

    return meta_sai_remove_oid(
            SAI_OBJECT_TYPE_NEXT_HOP,
            next_hop_id,
            &redis_generic_remove);
}

/**
 * Routine Description:
 *    @brief Set Next Hop attribute
 *
 * Arguments:
 *    @param[in] next_hop_id - next hop id
 *    @param[in] attr - attribute
 *
 * Return Values:
 *    @return SAI_STATUS_SUCCESS on success
 *            Failure status code on error
 */
sai_status_t redis_set_next_hop_attribute(
        _In_ sai_object_id_t next_hop_id,
        _In_ const sai_attribute_t *attr)
{
    std::lock_guard<std::mutex> lock(g_apimutex);

    SWSS_LOG_ENTER();

    return meta_sai_set_oid(
            SAI_OBJECT_TYPE_NEXT_HOP,
            next_hop_id,
            attr,
            &redis_generic_set);
}

/**
 * Routine Description:
 *    @brief Get Next Hop attribute
 *
 * Arguments:
 *    @param[in] next_hop_id - next hop id
 *    @param[in] attr_count - number of attributes
 *    @param[inout] attr_list - array of attributes
 *
 * Return Values:
 *    @return SAI_STATUS_SUCCESS on success
 *            Failure status code on error
 */
sai_status_t redis_get_next_hop_attribute(
        _In_ sai_object_id_t next_hop_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list)
{
    std::lock_guard<std::mutex> lock(g_apimutex);

    SWSS_LOG_ENTER();

    return meta_sai_get_oid(
            SAI_OBJECT_TYPE_NEXT_HOP,
            next_hop_id,
            attr_count,
            attr_list,
            &redis_generic_get);
}

/**
 * @brief Next Hop methods table retrieved with sai_api_query()
 */
const sai_next_hop_api_t redis_next_hop_api = {
    redis_create_next_hop,
    redis_remove_next_hop,
    redis_set_next_hop_attribute,
    redis_get_next_hop_attribute,
};
