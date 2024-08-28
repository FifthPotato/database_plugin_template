#include "irods/authenticate.h"
#include "irods/checksum.h"
#include "irods/icatHighLevelRoutines.hpp"
#include "irods/icatStructs.hpp"
#include "irods/irods_auth_constants.hpp"
#include "irods/irods_auth_factory.hpp"
#include "irods/irods_auth_manager.hpp"
#include "irods/irods_auth_object.hpp"
#include "irods/irods_auth_plugin.hpp"
#include "irods/irods_children_parser.hpp"
#include "irods/irods_database_constants.hpp"
#include "irods/irods_database_plugin.hpp"
#include "irods/irods_hierarchy_parser.hpp"
#include "irods/irods_lexical_cast.hpp"
#include "irods/irods_logger.hpp"
#include "irods/irods_pam_auth_object.hpp"
#include "irods/irods_postgres_object.hpp"
#include "irods/irods_random.hpp"
#include "irods/irods_resource_manager.hpp"
#include "irods/irods_rs_comm_query.hpp"
#include "irods/irods_server_properties.hpp"
#include "irods/irods_stacktrace.hpp"
#include "irods/irods_virtual_path.hpp"
#include "irods/key_value_proxy.hpp"
#include "irods/miscServerFunct.hpp"
#include "irods/modAccessControl.h"
#include "irods/msParam.h"
#include "irods/rcConnect.h"
#include "irods/rcMisc.h"
#include "irods/rods.h"
#include "irods/rodsDef.h"
#include "irods/rodsErrorTable.h"
#include "irods/rodsQuota.h"
#include "irods/user_validation_utilities.hpp"

#include <fmt/chrono.h>
#include <fmt/format.h>
#include <nlohmann/json.hpp>

#include <boost/date_time.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/regex.hpp>

#include <algorithm>
#include <cctype>
#include <charconv>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <locale>
#include <memory>
#include <sstream>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>
#include <vector>

const std::string ICSS_PROP( "irods_icss_property" );

// =-=-=-=-=-=-=-
// Appears to be completely unused?
// TODO: ask about this
// All references point to db_start_operation, defined below, which was stubbed out to begin with
irods::error db_start_op(
    irods::plugin_context& _ctx ) {
    return SUCCESS(); //TODO - stub
} // db_start_op

// =-=-=-=-=-=-=-
// set debug behavior for plugin
// Read value of _mode and set plugin behavior accordingly
irods::error db_debug_op(
    irods::plugin_context& _ctx,
    const char*            _mode ) {
    return SUCCESS(); //TODO - stub
} // db_debug_op

// =-=-=-=-=-=-=-
// open a database connection
// Begins a database connection.
// Should put the plugin's icatSessionStruct member (see irods/icatStructs.hpp) in a state that is ready to accept queries.
// Specifically, should populate icss members environPtr and connectPtr.
// This should also include any necessary authentication steps.
irods::error db_open_op(
    irods::plugin_context& _ctx ) {
    return SUCCESS(); //TODO - stub
} // db_open_op

// =-=-=-=-=-=-=-
// close a database connection
// Closes a database connection.
// Should put the plugin's icatSessionStruct member (see irods/icatStructs.hpp) in a cleaned-up state that cannot accept queries.
// Should additionally free any memory allocated for icss members environPtr and connectPtr, and set them to NULL.
// This may also include handling for pending queries, etc. 
irods::error db_close_op(
    irods::plugin_context& _ctx ) {
    return SUCCESS(); //TODO - stub
} // db_close_op

// =-=-=-=-=-=-=-
// return the local zone
irods::error db_check_and_get_object_id_op(
    irods::plugin_context& _ctx,
    const char*            _type,
    const char*            _name,
    const char*            _access ) {
    return SUCCESS(); //TODO - stub
} // db_check_and_get_object_id_op

// =-=-=-=-=-=-=-
// return the local zone
irods::error db_get_local_zone_op(
    irods::plugin_context& _ctx,
    std::string*           _zone ) {
    return SUCCESS(); //TODO - stub
} // db_get_local_zone_op

// =-=-=-=-=-=-=-
// update the data obj count of a resource
irods::error db_update_resc_obj_count_op(
    irods::plugin_context& _ctx,
    const std::string*     _resc,
    int                    _delta ) {

    return SUCCESS();

} // db_update_resc_obj_count_op

// =-=-=-=-=-=-=-
// update the data obj count of a resource
irods::error db_mod_data_obj_meta_op(
    irods::plugin_context& _ctx,
    dataObjInfo_t*         _data_obj_info,
    keyValPair_t*          _reg_param ) {
    return SUCCESS(); //TODO - stub
} // db_mod_data_obj_meta_op


// =-=-=-=-=-=-=-
// update the data obj count of a resource
irods::error db_reg_data_obj_op(
    irods::plugin_context& _ctx,
    dataObjInfo_t*         _data_obj_info ) {
    return SUCCESS(); //TODO - stub
} // db_reg_data_obj_op


// =-=-=-=-=-=-=-
// register a data object into the catalog
irods::error db_reg_replica_op(
    irods::plugin_context& _ctx,
    dataObjInfo_t*         _src_data_obj_info,
    dataObjInfo_t*         _dst_data_obj_info,
    keyValPair_t*          _cond_input ) {
    return SUCCESS(); //TODO - stub
} // db_reg_replica_op

// =-=-=-=-=-=-=-
// unregister a data object
irods::error db_unreg_replica_op(
    irods::plugin_context& _ctx,
    dataObjInfo_t*         _data_obj_info,
    keyValPair_t*          _cond_input ) {
    return SUCCESS(); //TODO - stub
} // db_unreg_replica_op

// =-=-=-=-=-=-=-
//
irods::error db_reg_rule_exec_op(
    irods::plugin_context& _ctx,
    ruleExecSubmitInp_t*   _re_sub_inp ) {
    return SUCCESS(); //TODO - stub
} // db_reg_rule_exec_op

// =-=-=-=-=-=-=-
// Modify an existing rule in the catalog.
irods::error db_mod_rule_exec_op(
    irods::plugin_context& _ctx,
    const char*            _re_id,
    keyValPair_t*          _reg_param )
{
    return SUCCESS(); //TODO - stub
} // db_mod_rule_exec_op

irods::error db_del_rule_exec_op(irods::plugin_context& _ctx, const char* _re_id)
{
    return SUCCESS(); //TODO - stub
} // db_del_rule_exec_op

irods::error db_add_child_resc_op(
    irods::plugin_context& _ctx,
    std::map<std::string, std::string> *_resc_input ) {
    return SUCCESS(); //TODO - stub
} // db_add_child_resc_op

// =-=-=-=-=-=-=-
//
irods::error db_reg_resc_op(
    irods::plugin_context& _ctx,
    std::map<std::string, std::string> *_resc_input ) {
    return SUCCESS(); //TODO - stub
} // db_reg_resc_op

// =-=-=-=-=-=-=-
//
irods::error db_del_child_resc_op(
    irods::plugin_context& _ctx,
    std::map<std::string, std::string> *_resc_input ) {
    return SUCCESS(); //TODO - stub
} // db_del_child_resc_op

// =-=-=-=-=-=-=-
// delete a resource
irods::error db_del_resc_op(
    irods::plugin_context& _ctx,
    const char *_resc_name,
    int                    _dry_run ) {
    return SUCCESS(); //TODO - stub
} // db_del_resc_op

// =-=-=-=-=-=-=-
// rollback the db
irods::error db_rollback_op(
    irods::plugin_context& _ctx ) {
    return SUCCESS(); //TODO - stub
} // db_rollback_op

// =-=-=-=-=-=-=-
// commit the transaction
irods::error db_commit_op(
    irods::plugin_context& _ctx ) {
    return SUCCESS(); //TODO - stub
} // db_commit_op

// =-=-=-=-=-=-=-
// commit the transaction
irods::error db_del_user_re_op(
    irods::plugin_context& _ctx,
    userInfo_t*            _user_info ) {
    return SUCCESS(); //TODO - stub
} // db_del_user_re_op

// =-=-=-=-=-=-=-
// commit the transaction
irods::error db_reg_coll_by_admin_op(
    irods::plugin_context& _ctx,
    collInfo_t*            _coll_info ) {
    return SUCCESS(); //TODO - stub
} // db_reg_coll_by_admin_op

// =-=-=-=-=-=-=-
// commit the transaction
irods::error db_reg_coll_op(
    irods::plugin_context& _ctx,
    collInfo_t*            _coll_info ) {
    return SUCCESS(); //TODO - stub
} // db_reg_coll_op

// =-=-=-=-=-=-=-
// commit the transaction
irods::error db_mod_coll_op(
    irods::plugin_context& _ctx,
    collInfo_t*            _coll_info ) {
    return SUCCESS(); //TODO - stub
} // db_mod_coll_op

// =-=-=-=-=-=-=-
// commit the transaction
irods::error db_reg_zone_op(
    irods::plugin_context& _ctx,
    const char*            _zone_name,
    const char*            _zone_type,
    const char*            _zone_conn_info,
    const char*            _zone_comment ) {
    return SUCCESS(); //TODO - stub
} // db_reg_zone_op

// =-=-=-=-=-=-=-
// modify the zone
irods::error db_mod_zone_op(
    irods::plugin_context& _ctx,
    const char*            _zone_name,
    const char*            _option,
    const char*            _option_value ) {
    return SUCCESS(); //TODO - stub
} // db_mod_zone_op

// =-=-=-=-=-=-=-
// modify the zone
irods::error db_rename_coll_op(
    irods::plugin_context& _ctx,
    const char*            _old_coll,
    const char*            _new_coll ) {
    return SUCCESS(); //TODO - stub
} // db_rename_coll_op

// =-=-=-=-=-=-=-
// modify the zone
irods::error db_mod_zone_coll_acl_op(
    irods::plugin_context& _ctx,
    const char*            _access_level,
    const char*            _user_name,
    const char*            _path_name ) {
    return SUCCESS(); //TODO - stub
} // db_mod_zone_coll_acl_op

// =-=-=-=-=-=-=-
// modify the zone
irods::error db_rename_local_zone_op(
    irods::plugin_context& _ctx,
    const char*            _old_zone,
    const char*            _new_zone ) {
    return SUCCESS(); //TODO - stub
} // db_rename_local_zone_op

// =-=-=-=-=-=-=-
// modify the zone
irods::error db_del_zone_op(
    irods::plugin_context& _ctx,
    const char*            _zone_name ) {
    return SUCCESS(); //TODO - stub
} // db_del_zone_op

irods::error db_simple_query_op(
    irods::plugin_context& _ctx,
    const char*            _sql,
    const char*            _arg1,
    const char*            _arg2,
    const char*            _arg3,
    const char*            _arg4,
    int                    _format,
    int*                   _control,
    char*                  _out_buf,
    int                    _max_out_buf ) {
    return SUCCESS(); //TODO - stub
} // db_simple_query_op

// =-=-=-=-=-=-=-
// commit the transaction
irods::error db_del_coll_by_admin_op(
    irods::plugin_context& _ctx,
    collInfo_t*            _coll_info ) {
    return SUCCESS(); //TODO - stub
} // db_del_coll_by_admin_op

// =-=-=-=-=-=-=-
// commit the transaction
irods::error db_del_coll_op(
    irods::plugin_context& _ctx,
    collInfo_t*            _coll_info ) {
    return SUCCESS(); //TODO - stub
} // db_del_coll_op

// =-=-=-=-=-=-=-
// authenticate user
irods::error db_check_auth_op(
    irods::plugin_context& _ctx,
    const char*            _scheme,
    const char*            _challenge,
    const char*            _response,
    const char*            _user_name,
    int*                   _user_priv_level,
    int*                   _client_priv_level ) {
    return SUCCESS(); //TODO - stub
} // db_check_auth_op

// =-=-=-=-=-=-=-
// authenticate user
irods::error db_make_temp_pw_op(
    irods::plugin_context& _ctx,
    char*                  _pw_value_to_hash,
    const char*            _other_user ) {
    return SUCCESS(); //TODO - stub
} // db_make_temp_pw_op

// =-=-=-=-=-=-=-
// authenticate user
irods::error db_make_limited_pw_op(
    irods::plugin_context& _ctx,
    int                    _ttl,
    char*                  _pw_value_to_hash ) {
    return SUCCESS(); //TODO - stub
} // db_make_limited_pw_op

// =-=-=-=-=-=-=-
// authenticate user
auto db_update_pam_password_op(irods::plugin_context& _ctx,
                               const char* _user_name,
                               int _ttl,
                               const char* _test_time,
                               char** _password_buffer,
                               std::size_t _password_buffer_size) -> irods::error
{
    return SUCCESS(); //TODO - stub
} // db_update_pam_password_op

// =-=-=-=-=-=-=-
// authenticate user
irods::error db_mod_user_op(
    irods::plugin_context& _ctx,
    const char*            _user_name,
    const char*            _option,
    const char*            _new_value ) {
    return SUCCESS(); //TODO - stub
} // db_mod_user_op

// =-=-=-=-=-=-=-
// authenticate user
irods::error db_mod_group_op(
    irods::plugin_context& _ctx,
    const char*            _group_name,
    const char*            _option,
    const char*            _user_name,
    const char*            _user_zone ) {
    return SUCCESS(); //TODO - stub
} // db_mod_group_op

// =-=-=-=-=-=-=-
// authenticate user
irods::error db_mod_resc_op(
    irods::plugin_context& _ctx,
    const char*            _resc_name,
    const char*            _option,
    const char*            _option_value ) {
    return SUCCESS(); //TODO - stub
} // db_mod_resc_op

// =-=-=-=-=-=-=-
// authenticate user
irods::error db_mod_resc_data_paths_op(
    irods::plugin_context& _ctx,
    const char*            _resc_name,
    const char*            _old_path,
    const char*            _new_path,
    const char*            _user_name ) {
    return SUCCESS(); //TODO - stub
} // db_mod_resc_data_paths_op

// =-=-=-=-=-=-=-
// authenticate user
irods::error db_mod_resc_freespace_op(
    irods::plugin_context& _ctx,
    const char*            _resc_name,
    int                    _update_value ) {
    return SUCCESS(); //TODO - stub
} // db_mod_resc_freespace_op

// =-=-=-=-=-=-=-
// commit the transaction
irods::error db_reg_user_re_op(
    irods::plugin_context& _ctx,
    userInfo_t*            _user_info ) {
    return SUCCESS(); //TODO - stub
} // db_reg_user_re_op

// =-=-=-=-=-=-=-
// commit the transaction
irods::error db_set_avu_metadata_op(
    irods::plugin_context& _ctx,
    const char*            _type,
    const char*            _name,
    const char*            _attribute,
    const char*            _new_value,
    const char*            _new_unit,
    const KeyValPair*      _cond_input)
{
    return SUCCESS(); //TODO - stub
} // db_set_avu_metadata_op

#define ACCESS_MAX 999999  /* A large access value (larger than the
maximum used (i.e. for fail safe)) and
    also indicates not initialized*/
// =-=-=-=-=-=-=-
// Add an Attribute-Value [Units] pair/triple metadata item to one or
// more data objects.  This is the Wildcard version, where the
// collection/data-object name can match multiple objects).

// The return value is error code (negative) or the number of objects
// to which the AVU was associated.
irods::error db_add_avu_metadata_wild_op(
    irods::plugin_context& _ctx,
    const char*            _type,
    const char*            _name,
    const char*            _attribute,
    const char*            _value,
    const char*            _units,
    const KeyValPair*      _cond_input)
{
    return SUCCESS(); //TODO - stub
} // db_add_avu_metadata_wild_op

irods::error db_add_avu_metadata_op(
    irods::plugin_context& _ctx,
    const char*            _type,
    const char*            _name,
    const char*            _attribute,
    const char*            _value,
    const char*            _units,
    const KeyValPair*      _cond_input)
{
    return SUCCESS(); //TODO - stub
} // db_add_avu_metadata_op

irods::error db_mod_avu_metadata_op(
    irods::plugin_context& _ctx,
    const char*            _type,
    const char*            _name,
    const char*            _attribute,
    const char*            _value,
    const char*            _unitsOrArg0,
    const char*            _arg1,
    const char*            _arg2,
    const char*            _arg3,
    const KeyValPair*      _cond_input)
{
    return SUCCESS(); //TODO - stub
} // db_mod_avu_metadata_op

irods::error db_del_avu_metadata_op(
    irods::plugin_context& _ctx,
    int                    _option,
    const char*            _type,
    const char*            _name,
    const char*            _attribute,
    const char*            _value,
    const char*            _unit,
    int                    _nocommit,
    const KeyValPair*      _cond_input)
{
    return SUCCESS(); //TODO - stub
} // db_del_avu_metadata_op

irods::error db_copy_avu_metadata_op(
    irods::plugin_context& _ctx,
    const char*            _type1,
    const char*            _type2,
    const char*            _name1,
    const char*            _name2,
    const KeyValPair*      _cond_input)
{
    return SUCCESS(); //TODO - stub
} // db_copy_avu_metadata_op

irods::error db_mod_access_control_resc_op(
    irods::plugin_context& _ctx,
    const int                    _recursive_flag,
    const char*                  _access_level,
    const char*                  _user_name,
    const char*                  _zone,
    const char*                  _resc_name ) {
    return SUCCESS(); //TODO - stub
} // db_mod_access_control_resc_op

irods::error db_mod_access_control_op(
    irods::plugin_context& _ctx,
    const int                    _recursive_flag,
    const char*                  _access_level,
    const char*                  _user_name,
    const char*                  _zone,
    const char*                  _path_name ) {
    return SUCCESS(); //TODO - stub
} // db_mod_access_control_op

irods::error db_rename_object_op(
    irods::plugin_context& _ctx,
    rodsLong_t             _obj_id,
    const char*            _new_name ) {
    return SUCCESS(); //TODO - stub
} // db_rename_object_op

irods::error db_move_object_op(
    irods::plugin_context& _ctx,
    rodsLong_t             _obj_id,
    rodsLong_t             _target_coll_id ) {
    return SUCCESS(); //TODO - stub
} // db_move_object_op

irods::error db_reg_token_op(
    irods::plugin_context& _ctx,
    const char*            _name_space,
    const char*            _name,
    const char*            _value,
    const char*            _value2,
    const char*            _value3,
    const char*            _comment ) {
    return SUCCESS(); //TODO - stub
} // db_reg_token_op

irods::error db_del_token_op(
    irods::plugin_context& _ctx,
    const char*            _name_space,
    const char*            _name ) {
    return SUCCESS(); //TODO - stub
} // db_del_token_op

irods::error db_reg_server_load_op(
    irods::plugin_context& _ctx,
    const char*            _host_name,
    const char*            _resc_name,
    const char*            _cpu_used,
    const char*            _mem_used,
    const char*            _swap_used,
    const char*            _run_q_load,
    const char*            _disk_space,
    const char*            _net_input,
    const char*            _net_output ) {
    return SUCCESS(); //TODO - stub
} // db_reg_server_load_op

irods::error db_purge_server_load_op(
    irods::plugin_context& _ctx,
    const char*            _seconds_ago ) {
    return SUCCESS(); //TODO - stub
} // db_purge_server_load_op

irods::error db_reg_server_load_digest_op(
    irods::plugin_context& _ctx,
    const char*            _resc_name,
    const char*            _load_factor ) {
    return SUCCESS(); //TODO - stub
} // db_reg_server_load_digest_op

irods::error db_purge_server_load_digest_op(
    irods::plugin_context& _ctx,
    const char*            _seconds_ago ) {
    return SUCCESS(); //TODO - stub
} // db_purge_server_load_digest_op

irods::error db_get_grid_configuration_value_op(
    irods::plugin_context& _ctx,
    const char*            _namespace,
    const char*            _option_name,
    char*                  _option_value,
    std::size_t            _option_value_buffer_size)
{
    return SUCCESS(); //TODO - stub
} // db_get_grid_configuration_value_op

irods::error db_set_grid_configuration_value_op(
    irods::plugin_context& _ctx,
    const char*            _namespace,
    const char*            _option_name,
    const char*            _option_value)
{
    return SUCCESS(); //TODO - stub
} // db_set_grid_configuration_value_op

irods::error db_calc_usage_and_quota_op(
    irods::plugin_context& _ctx ) {
    return SUCCESS(); //TODO - stub
} // db_calc_usage_and_quota_op

irods::error db_set_quota_op(
    irods::plugin_context& _ctx,
    const char*            _type,
    const char*            _name,
    const char*            _resc_name,
    const char*            _limit ) {
    return SUCCESS(); //TODO - stub
} // db_set_quota_op

irods::error db_check_quota_op(
    irods::plugin_context& _ctx,
    const char*            _user_name,
    const char*            _resc_name,
    rodsLong_t*            _user_quota,
    int*                   _quota_status ) {
    return SUCCESS(); //TODO - stub
} // db_check_quota_op

irods::error db_del_unused_avus_op(irods::plugin_context& _ctx)
{
    return SUCCESS(); //TODO - stub
} // db_del_unused_avus_op

irods::error db_ins_rule_table_op(
    irods::plugin_context& _ctx,
    const char*            _base_name,
    const char*            _map_priority_str,
    const char*            _rule_name,
    const char*            _rule_head,
    const char*            _rule_condition,
    const char*            _rule_action,
    const char*            _rule_recovery,
    const char*            _rule_id_str,
    const char*            _my_time ) {
    return SUCCESS(); //TODO - stub
} // db_ins_rule_table_op

irods::error db_ins_dvm_table_op(
    irods::plugin_context& _ctx,
    const char*            _base_name,
    const char*            _var_name,
    const char*            _action,
    const char*            _var_2_cmap,
    const char*            _my_time ) {
    return SUCCESS(); //TODO - stub
} // db_ins_dvm_table_op

irods::error db_ins_fnm_table_op(
    irods::plugin_context& _ctx,
    const char*            _base_name,
    const char*            _func_name,
    const char*            _func_2_cmap,
    const char*            _my_time ) {
    return SUCCESS(); //TODO - stub
} // db_ins_fnm_table_op

irods::error db_ins_msrvc_table_op(
    irods::plugin_context& _ctx,
    const char*            _module_name,
    const char*            _msrvc_name,
    const char*            _msrvc_signature,
    const char*            _msrvc_version,
    const char*            _msrvc_host,
    const char*            _msrvc_location,
    const char*            _msrvc_language,
    const char*            _msrvc_type_name,
    const char*            _msrvc_status,
    const char*            _my_time ) {
    return SUCCESS(); //TODO - stub
} // db_ins_msrvc_table_op

irods::error db_version_rule_base_op(
    irods::plugin_context& _ctx,
    const char*            _base_name,
    const char*            _my_time ) {
    return SUCCESS(); //TODO - stub
} // db_version_rule_base_op

irods::error db_version_dvm_base_op(
    irods::plugin_context& _ctx,
    const char*            _base_name,
    const char*            _my_time ) {
    return SUCCESS(); //TODO - stub
} // db_version_dvm_base_op

irods::error db_version_fnm_base_op(
    irods::plugin_context& _ctx,
    const char*            _base_name,
    const char*            _my_time ) {
    return SUCCESS(); //TODO - stub
} // db_version_fnm_base_op

irods::error db_add_specific_query_op(
    irods::plugin_context& _ctx,
    const char*            _sql,
    const char*            _alias ) {
    return SUCCESS(); //TODO - stub
} // db_add_specific_query_op

irods::error db_del_specific_query_op(
    irods::plugin_context& _ctx,
    const char*            _sql_or_alias ) {
    return SUCCESS(); //TODO - stub
} // db_del_specific_query_op

#define MINIMUM_COL_SIZE 50
irods::error db_specific_query_op(
    irods::plugin_context& _ctx,
    specificQueryInp_t*    _spec_query_inp,
    genQueryOut_t*         _result ) {
    return SUCCESS(); //TODO - stub
} // db_specific_query_op

irods::error db_get_distinct_data_obj_count_on_resource_op(
    irods::plugin_context& _ctx,
    const char*            _resc_name,
    long long*             _count ) {
    return SUCCESS(); //TODO - stub
} // db_get_distinct_data_obj_count_on_resource_op

irods::error db_get_distinct_data_objs_missing_from_child_given_parent_op(
    irods::plugin_context& _ctx,
    const std::string*     _parent,
    const std::string*     _child,
    int                    _limit,
    dist_child_result_t*   _results ) {
    return SUCCESS(); //TODO - stub
} // db_get_distinct_data_objs_missing_from_child_given_parent_op

irods::error db_get_repl_list_for_leaf_bundles_op(
    irods::plugin_context&      _ctx,
    rodsLong_t                  _count,
    size_t                      _child_index,
    const std::vector<leaf_bundle_t>* _bundles,
    const std::string*          _invocation_timestamp,
    dist_child_result_t*        _results ) {
    return SUCCESS(); //TODO - stub
} // db_get_repl_list_for_leaf_bundles_op

irods::error db_get_hierarchy_for_resc_op(
    irods::plugin_context& _ctx,
    const std::string*     _resc_name,
    const std::string*     _zone_name,
    std::string*           _hierarchy ) {
    return SUCCESS(); //TODO - stub
} // db_get_hierarchy_for_resc_op

// NOLINTNEXTLINE(readability-function-cognitive-complexity)
irods::error db_mod_ticket_op(
    irods::plugin_context& _ctx,
    const char*            _op_name,
    const char*            _ticket_string,
    const char*            _arg3,
    const char*            _arg4,
    const char*            _arg5,
    const KeyValPair*      _cond_input)
{
    return SUCCESS(); //TODO - stub
} // db_mod_ticket_op

irods::error db_get_icss_op(
    irods::plugin_context& _ctx,
    icatSessionStruct**    _icss ) {
    return SUCCESS(); //TODO - stub
} // db_get_icss_op

// =-=-=-=-=-=-=-
// from general_query.cpp ::
int chl_gen_query_impl( genQueryInp_t, genQueryOut_t* );

irods::error db_gen_query_op(
    irods::plugin_context& _ctx,
    genQueryInp_t*         _gen_query_inp,
    genQueryOut_t*         _result ) {
    return SUCCESS(); //TODO - stub
} // db_gen_query_op

// =-=-=-=-=-=-=-
// from general_query.cpp ::
int chl_gen_query_access_control_setup_impl( const char*, const char*, const char*, int, int );

irods::error db_gen_query_access_control_setup_op(
    irods::plugin_context& _ctx,
    const char*            _user,
    const char*            _zone,
    const char*            _host,
    int                    _priv,
    int                    _control_flag ) {
    return SUCCESS(); //TODO - stub
} // db_gen_query_access_control_setup_op

// =-=-=-=-=-=-=-
// from general_query.cpp ::
int chl_gen_query_ticket_setup_impl( const char*, const char* );

irods::error db_gen_query_ticket_setup_op(
    irods::plugin_context& _ctx,
    const char*            _ticket,
    const char*            _client_addr ) {
    return SUCCESS(); //TODO - stub
} // db_gen_query_ticket_setup_op

// =-=-=-=-=-=-=-
// from general_query.cpp ::
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
int chl_general_update_impl( generalUpdateInp_t );
#pragma GCC diagnostic pop

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
irods::error db_general_update_op(
    irods::plugin_context& _ctx,
    generalUpdateInp_t*    _update_inp ) {
    return SUCCESS(); //TODO - stub
} // db_general_update_op

auto db_check_permission_to_modify_data_object_op(
    irods::plugin_context& _ctx,
    const rodsLong_t       _data_id) -> irods::error
{
    return SUCCESS(); //TODO - stub
} // db_check_permission_to_modify_data_object_op

auto db_update_ticket_write_byte_count_op(
    irods::plugin_context& _ctx,
    const rodsLong_t       _data_id,
    const rodsLong_t       _bytes_written) -> irods::error
{
    return SUCCESS(); //TODO - stub
} // db_update_ticket_write_byte_count_op

auto db_get_delay_rule_info_op(irods::plugin_context& _ctx, const char* _rule_id, std::vector<std::string>* _info)
    -> irods::error
{
    return SUCCESS(); //TODO - stub
} // db_get_delay_rule_info_op

auto db_data_object_finalize_op(irods::plugin_context& _ctx, const char* _json_input) -> irods::error
{
    return SUCCESS(); //TODO - stub
} // db_data_object_finalize_op

auto db_check_auth_credentials_op(irods::plugin_context& _ctx,
                                  const char* _username,
                                  const char* _zone,
                                  const char* _password,
                                  int* _correct) -> irods::error
{
    return SUCCESS(); //TODO - stub
} // db_check_auth_credentials_op

auto db_execute_genquery2_sql(irods::plugin_context& _ctx,
                              const char* _sql,
                              const std::vector<std::string>* _values,
                              char** _output) -> irods::error
{
    return SUCCESS(); //TODO - stub
} // db_execute_genquery2_sql

// =-=-=-=-=-=-=-
//
irods::error db_start_operation( irods::plugin_property_map& _props ) {
    return SUCCESS();

} // db_start_operation


// =-=-=-=-=-=-=-
// derive a new tcp network plugin from
// the network plugin base class for handling
// tcp communications
class postgres_database_plugin : public irods::database {
    public:
        postgres_database_plugin(const std::string& _nm, const std::string& _ctx)
            : irods::database(_nm, _ctx)
        {

            // create a property for the icat session
            // which will manage the lifetime of the db
            // connection - use a copy ctor to init
            icatSessionStruct icss;
            std::memset(&icss, 0, sizeof(icss));
            properties_.set< icatSessionStruct >( ICSS_PROP, icss );

            set_start_operation( db_start_operation );
        } // TODO: stub, maybe rename class?

        ~postgres_database_plugin()
        {
        }
}; // class postgres_database_plugin

// =-=-=-=-=-=-=-
// factory function to provide instance of the plugin
extern "C"
irods::database* plugin_factory(
    const std::string& _inst_name,
    const std::string& _context ) {
    // =-=-=-=-=-=-=-
    // create a postgres database plugin instance
    postgres_database_plugin* pg = new postgres_database_plugin(
        _inst_name,
        _context );

    // =-=-=-=-=-=-=-
    // fill in the operation table mapping call
    // names to function na,mes
    using namespace irods;
    using namespace std;
    pg->add_operation(
        DATABASE_OP_START,
        function<error(plugin_context&)>(
            db_start_op ) );
    pg->add_operation(
        DATABASE_OP_DEBUG,
        function<error(plugin_context&, const char*)>(
            db_debug_op ) );
    pg->add_operation(
        DATABASE_OP_OPEN,
        function<error(plugin_context&)>(
            db_open_op ) );
    pg->add_operation(
        DATABASE_OP_CLOSE,
        function<error(plugin_context&)>(
            db_close_op ) );
    pg->add_operation(
        DATABASE_OP_GET_LOCAL_ZONE,
        function<error(plugin_context&,std::string*)>(
            db_get_local_zone_op ) );
    pg->add_operation(
        DATABASE_OP_UPDATE_RESC_OBJ_COUNT,
        function<error(plugin_context&,const std::string*, int)>(
            db_update_resc_obj_count_op ) );
    pg->add_operation(
        DATABASE_OP_MOD_DATA_OBJ_META,
        function<error(plugin_context&,dataObjInfo_t*,keyValPair_t*)>(
            db_mod_data_obj_meta_op ) );
    pg->add_operation(
        DATABASE_OP_REG_DATA_OBJ,
        function<error(plugin_context&,dataObjInfo_t*)>(
            db_reg_data_obj_op ) );
    pg->add_operation(
        DATABASE_OP_REG_REPLICA,
        function<error(plugin_context&,dataObjInfo_t*,dataObjInfo_t*,keyValPair_t*)>(
            db_reg_replica_op ) );
    pg->add_operation(
        DATABASE_OP_UNREG_REPLICA,
        function<error(plugin_context&,dataObjInfo_t*,keyValPair_t*)>(
            db_unreg_replica_op ) );
    pg->add_operation(
        DATABASE_OP_REG_RULE_EXEC,
        function<error(plugin_context&,ruleExecSubmitInp_t*)>(
            db_reg_rule_exec_op ) );
    pg->add_operation(
        DATABASE_OP_MOD_RULE_EXEC,
        function<error(plugin_context&,const char*,keyValPair_t*)>(
            db_mod_rule_exec_op ) );
    pg->add_operation(
        DATABASE_OP_DEL_RULE_EXEC,
        function<error(plugin_context&,const char*)>(
            db_del_rule_exec_op ) );
    pg->add_operation(
        DATABASE_OP_ADD_CHILD_RESC,
        function<error(plugin_context&,map<string,string>*)>(
            db_add_child_resc_op ) );
    pg->add_operation(
        DATABASE_OP_REG_RESC,
        function<error(plugin_context&,map<string, string>*)>(
            db_reg_resc_op ) );
    pg->add_operation(
        DATABASE_OP_DEL_CHILD_RESC,
        function<error(plugin_context&,map<string,string>*)>(
            db_del_child_resc_op ) );
    pg->add_operation(
        DATABASE_OP_DEL_RESC,
        function<error(plugin_context&,const char*,int)>(
            db_del_resc_op ) );
    pg->add_operation(
        DATABASE_OP_ROLLBACK,
        function<error(plugin_context&)>(
            db_rollback_op ) );
    pg->add_operation(
        DATABASE_OP_COMMIT,
        function<error(plugin_context&)>(
            db_commit_op ) );
    pg->add_operation(
        DATABASE_OP_DEL_USER_RE,
        function<error(plugin_context&,userInfo_t*)>(
            db_del_user_re_op ) );
    pg->add_operation(
        DATABASE_OP_REG_COLL_BY_ADMIN,
        function<error(plugin_context&,collInfo_t*)>(
            db_reg_coll_by_admin_op ) );
    pg->add_operation(
        DATABASE_OP_REG_COLL,
        function<error(plugin_context&,collInfo_t*)>(
            db_reg_coll_op ) );
    pg->add_operation(
        DATABASE_OP_MOD_COLL,
        function<error(plugin_context&,collInfo_t*)>(
            db_mod_coll_op ) );
    pg->add_operation(
        DATABASE_OP_REG_ZONE,
        function<error(plugin_context&,const char*,const char*,const char*,const char*)>(
            db_reg_zone_op ) );
    pg->add_operation(
        DATABASE_OP_MOD_ZONE,
        function<error(plugin_context&,const char*,const char*,const char*)>(
            db_mod_zone_op ) );
    pg->add_operation(
        DATABASE_OP_RENAME_COLL,
        function<error(plugin_context&,const char*,const char*)>(
            db_rename_coll_op ) );
    pg->add_operation(
        DATABASE_OP_MOD_ZONE_COLL_ACL,
        function<error(plugin_context&,const char*,const char*,const char*)>(
            db_mod_zone_coll_acl_op ) );
    pg->add_operation(
        DATABASE_OP_RENAME_LOCAL_ZONE,
        function<error(plugin_context&,const char*,const char*)>(
            db_rename_local_zone_op ) );
    pg->add_operation(
        DATABASE_OP_DEL_ZONE,
        function<error(plugin_context&,const char*)>(
            db_del_zone_op ) );
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
    pg->add_operation(
        DATABASE_OP_SIMPLE_QUERY,
        function<error(plugin_context&,const char*,const char*,const char*,const char*,const char*,int,int*,char*,int)>(
            db_simple_query_op ) );
#pragma GCC diagnostic pop
    pg->add_operation(
        DATABASE_OP_DEL_COLL_BY_ADMIN,
        function<error(plugin_context&,collInfo_t*)>(
            db_del_coll_by_admin_op ) );
    pg->add_operation(
        DATABASE_OP_DEL_COLL,
        function<error(plugin_context&,collInfo_t*)>(
            db_del_coll_op ) );
    pg->add_operation(
        DATABASE_OP_CHECK_AUTH,
        function<error(plugin_context&,const char*,const char*,const char*,const char*,int*,int*)>(
            db_check_auth_op ) );
    pg->add_operation(
        DATABASE_OP_MAKE_TEMP_PW,
        function<error(plugin_context&,char*, const char*)>(
            db_make_temp_pw_op ) );
    pg->add_operation(DATABASE_OP_UPDATE_PAM_PASSWORD,
                      function<error(plugin_context&, const char*, int, const char*, char**, std::size_t)>(
                          db_update_pam_password_op));
    pg->add_operation(
        DATABASE_OP_MOD_USER,
        function<error(plugin_context&,const char*,const char*,const char*)>(
            db_mod_user_op ) );
    pg->add_operation(
        DATABASE_OP_MAKE_LIMITED_PW,
        function<error(plugin_context&,int,char*)>(
            db_make_limited_pw_op ) );
    pg->add_operation(
        DATABASE_OP_MOD_GROUP,
        function<error(plugin_context&,const char*,const char*,const char*,const char*)>(
            db_mod_group_op ) );
    pg->add_operation(
        DATABASE_OP_MOD_RESC,
        function<error(plugin_context&,const char*,const char*,const char*)>(
            db_mod_resc_op ) );
    pg->add_operation(
        DATABASE_OP_MOD_RESC_DATA_PATHS,
        function<error(plugin_context&,const char*,const char*,const char*,const char*)>(
            db_mod_resc_data_paths_op ) );
    pg->add_operation(
        DATABASE_OP_MOD_RESC_FREESPACE,
        function<error(plugin_context&,const char*,int)>(
            db_mod_resc_freespace_op ) );
    pg->add_operation(
        DATABASE_OP_REG_USER_RE,
        function<error(plugin_context&,userInfo_t*)>(
            db_reg_user_re_op ) );
    pg->add_operation(
        DATABASE_OP_SET_AVU_METADATA,
        function<error(plugin_context&,const char*,const char*,const char*,const char*,const char*,const KeyValPair*)>(
            db_set_avu_metadata_op ) );
    pg->add_operation(
        DATABASE_OP_ADD_AVU_METADATA_WILD,
        function<error(plugin_context&,const char*,const char*,const char*,const char*,const char*,const KeyValPair*)>(
            db_add_avu_metadata_wild_op ) );
    pg->add_operation(
        DATABASE_OP_ADD_AVU_METADATA,
        function<error(plugin_context&,const char*,const char*,const char*,const char*,const char*,const KeyValPair*)>(
            db_add_avu_metadata_op ) );
    pg->add_operation(
        DATABASE_OP_MOD_AVU_METADATA,
        function<error(plugin_context&,const char*,const char*,const char*,const char*,const char*,const char*,const char*,const char*,const KeyValPair*)>(
            db_mod_avu_metadata_op ) );
    pg->add_operation(
        DATABASE_OP_DEL_AVU_METADATA,
        function<error(plugin_context&,int,const char*,const char*,const char*,const char*,const char*,int,const KeyValPair*)>(
            db_del_avu_metadata_op ) );
    pg->add_operation(
        DATABASE_OP_COPY_AVU_METADATA,
        function<error(plugin_context&,const char*,const char*,const char*,const char*,const KeyValPair*)>(
            db_copy_avu_metadata_op ) );
    pg->add_operation(
        DATABASE_OP_MOD_ACCESS_CONTROL_RESC,
        function<error(plugin_context&,int,const char*,const char*,const char*,const char*)>(
            db_mod_access_control_resc_op ) );
    pg->add_operation(
        DATABASE_OP_MOD_ACCESS_CONTROL,
        function<error(plugin_context&,int,const char*,const char*,const char*,const char*)>(
            db_mod_access_control_op ) );
    pg->add_operation(
        DATABASE_OP_RENAME_OBJECT,
        function<error(plugin_context&,rodsLong_t,const char*)>(
            db_rename_object_op ) );
    pg->add_operation(
        DATABASE_OP_MOVE_OBJECT,
        function<error(plugin_context&,rodsLong_t,rodsLong_t)>(
            db_move_object_op ) );
    pg->add_operation(
        DATABASE_OP_REG_TOKEN,
        function<error(plugin_context&,const char*,const char*,const char*,const char*,const char*,const char*)>(
            db_reg_token_op ) );
    pg->add_operation(
        DATABASE_OP_DEL_TOKEN,
        function<error(plugin_context&,const char*,const char*)>(
            db_del_token_op ) );
    pg->add_operation(
        DATABASE_OP_REG_SERVER_LOAD,
        function<error(plugin_context&,const char*,const char*,const char*,const char*,const char*,const char*,const char*,const char*,const char*)>(
            db_reg_server_load_op ) );
    pg->add_operation(
        DATABASE_OP_PURGE_SERVER_LOAD,
        function<error(plugin_context&,const char*)>(
            db_purge_server_load_op ) );
    pg->add_operation(
        DATABASE_OP_REG_SERVER_LOAD_DIGEST,
        function<error(plugin_context&,const char*,const char*)>(
            db_reg_server_load_digest_op ) );
    pg->add_operation(
        DATABASE_OP_PURGE_SERVER_LOAD_DIGEST,
        function<error(plugin_context&,const char*)>(
            db_purge_server_load_digest_op ) );
    pg->add_operation(
        DATABASE_OP_GET_GRID_CONFIGURATION_VALUE,
        function<error(plugin_context&, const char*, const char*, char*, std::size_t)>(
            db_get_grid_configuration_value_op));
    pg->add_operation(
        DATABASE_OP_SET_GRID_CONFIGURATION_VALUE,
        function<error(plugin_context&, const char*, const char*, const char*)>(
            db_set_grid_configuration_value_op));
    pg->add_operation(
        DATABASE_OP_CALC_USAGE_AND_QUOTA,
        function<error(plugin_context&)>(
            db_calc_usage_and_quota_op ) );
    pg->add_operation(
        DATABASE_OP_SET_QUOTA,
        function<error(plugin_context&,const char*,const char*,const char*,const char*)>(
            db_set_quota_op ) );
    pg->add_operation(
        DATABASE_OP_CHECK_QUOTA,
        function<error(plugin_context&,const char*,const char*,rodsLong_t*,int*)>(
            db_check_quota_op ) );
    pg->add_operation(
        DATABASE_OP_DEL_UNUSED_AVUS,
        function<error(plugin_context&)>(
            db_del_unused_avus_op ) );
    pg->add_operation(
        DATABASE_OP_INS_RULE_TABLE,
        function<error(plugin_context&,const char*,const char*,const char*,const char*,const char*,const char*,const char*,const char*,const char*)>(
            db_ins_rule_table_op ) );
    pg->add_operation(
        DATABASE_OP_INS_DVM_TABLE,
        function<error(plugin_context&,const char*,const char*,const char*,const char*,const char*)>(
            db_ins_dvm_table_op ) );
    pg->add_operation(
        DATABASE_OP_INS_FNM_TABLE,
        function<error(plugin_context&,const char*,const char*,const char*,const char*)>(
            db_ins_fnm_table_op ) );
    pg->add_operation(
        DATABASE_OP_INS_MSRVC_TABLE,
        function<error(plugin_context&,const char*,const char*,const char*,const char*,const char*,const char*,const char*,const char*,const char*,const char*)>(
            db_ins_msrvc_table_op ) );
    pg->add_operation(
        DATABASE_OP_VERSION_RULE_BASE,
        function<error(plugin_context&,const char*,const char*)>(
            db_version_rule_base_op ) );
    pg->add_operation(
        DATABASE_OP_VERSION_DVM_BASE,
        function<error(plugin_context&,const char*,const char*)>(
            db_version_dvm_base_op ) );
    pg->add_operation(
        DATABASE_OP_VERSION_FNM_BASE,
        function<error(plugin_context&,const char*,const char*)>(
            db_version_fnm_base_op ) );
    pg->add_operation(
        DATABASE_OP_ADD_SPECIFIC_QUERY,
        function<error(plugin_context&,const char*,const char*)>(
            db_add_specific_query_op ) );
    pg->add_operation(
        DATABASE_OP_DEL_SPECIFIC_QUERY,
        function<error(plugin_context&,const char*)>(
            db_del_specific_query_op ) );
    pg->add_operation(
        DATABASE_OP_SPECIFIC_QUERY,
        function<error(plugin_context&,specificQueryInp_t*,genQueryOut_t*)>(
            db_specific_query_op ) );
    pg->add_operation(
        DATABASE_OP_GET_HIERARCHY_FOR_RESC,
        function<error(plugin_context&,const string*, const string*,std::string*)>(
            db_get_hierarchy_for_resc_op ) );
    pg->add_operation(
        DATABASE_OP_MOD_TICKET,
        function<error(plugin_context&,const char*,const char*,const char*,const char*,const char*,const KeyValPair*)>(
            db_mod_ticket_op ) );
    pg->add_operation(
        DATABASE_OP_CHECK_AND_GET_OBJ_ID,
        function<error(plugin_context&,const char*,const char*,const char*)>(
            db_check_and_get_object_id_op ) );
    pg->add_operation(
        DATABASE_OP_GET_RCS,
        function<error(plugin_context&,icatSessionStruct**)>(
            db_get_icss_op ) );
    pg->add_operation(
        DATABASE_OP_GEN_QUERY,
        function<error(plugin_context&,genQueryInp_t*,genQueryOut_t*)>(
            db_gen_query_op ) );
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
    pg->add_operation(
        DATABASE_OP_GENERAL_UPDATE,
        function<error(plugin_context&,generalUpdateInp_t*)>(
            db_general_update_op ) );
#pragma GCC diagnostic pop
    pg->add_operation(
        DATABASE_OP_GEN_QUERY_ACCESS_CONTROL_SETUP,
        function<error(plugin_context&,const char*,const char*,const char*,int,int)>(
            db_gen_query_access_control_setup_op ) );
    pg->add_operation(
        DATABASE_OP_GEN_QUERY_TICKET_SETUP,
        function<error(plugin_context&,const char*,const char*)>(
            db_gen_query_ticket_setup_op ) );
    pg->add_operation(
        DATABASE_OP_GET_DISTINCT_DATA_OBJ_COUNT_ON_RESOURCE,
        function<error(plugin_context&,const char*,long long*)>(
            db_get_distinct_data_obj_count_on_resource_op ) );
    pg->add_operation(
        DATABASE_OP_GET_DISTINCT_DATA_OBJS_MISSING_FROM_CHILD_GIVEN_PARENT,
        function<error(plugin_context&,const string*, const string*, int, dist_child_result_t*)>(
            db_get_distinct_data_objs_missing_from_child_given_parent_op ) );
    pg->add_operation(
        DATABASE_OP_GET_REPL_LIST_FOR_LEAF_BUNDLES,
        function<error(plugin_context&,rodsLong_t,size_t,const std::vector<leaf_bundle_t>*,const std::string*,dist_child_result_t*)>(
            db_get_repl_list_for_leaf_bundles_op));
    pg->add_operation(
        DATABASE_OP_CHECK_PERMISSION_TO_MODIFY_DATA_OBJECT,
        function<error(plugin_context&,const rodsLong_t)>(
            db_check_permission_to_modify_data_object_op));
    pg->add_operation(
        DATABASE_OP_UPDATE_TICKET_WRITE_BYTE_COUNT,
        function<error(plugin_context&,const rodsLong_t,const rodsLong_t)>(
            db_update_ticket_write_byte_count_op));
    pg->add_operation<const char*, std::vector<std::string>*>(
        DATABASE_OP_GET_DELAY_RULE_INFO,
        function<error(plugin_context&, const char*, std::vector<std::string>*)>(db_get_delay_rule_info_op));
    pg->add_operation<const char*>(
        DATABASE_OP_DATA_OBJECT_FINALIZE, function<error(plugin_context&, const char*)>(db_data_object_finalize_op));
    pg->add_operation<const char*, const char*, const char*, int*>(
        DATABASE_OP_CHECK_AUTH_CREDENTIALS,
        function<error(plugin_context&, const char*, const char*, const char*, int*)>(db_check_auth_credentials_op));
    pg->add_operation<const char*, const std::vector<std::string>*, char**>(
        DATABASE_OP_EXECUTE_GENQUERY2_SQL,
        function<error(plugin_context&, const char*, const std::vector<std::string>*, char**)>(
            db_execute_genquery2_sql));

    return pg;
} // plugin_factory
