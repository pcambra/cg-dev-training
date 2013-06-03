<?php
/**
 * @file
 * commerce_sr.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_sr_default_rules_configuration() {
  $rule = rules_import('
  { "rules_create_a_simple_recommendation_entity" : {
    "LABEL" : "Create a Simple Recommendation Entity",
    "PLUGIN" : "reaction rule",
    "REQUIRES" : [ "rules", "commerce_sr", "commerce_cart" ],
    "ON" : [ "commerce_cart_product_add" ],
    "IF" : [
      { "user_has_role" : {
        "account" : [ "commerce-order:owner" ],
        "roles" : { "value" : { "2" : "2" } }
      }
    }
    ],
    "DO" : [
      { "commerce_sr_create_entity" : { "order" : [ "commerce-order" ], "product" : [ "commerce-product" ] } }
    ]
    }
    }
  ');

  $configs['rules_create_a_simple_recommendation_entity'] = $rule;

  return $configs;

}
