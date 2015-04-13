<?php

/**
 * @file
 * Definition of the 'list' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Bootstrap'),
  'description' => t('Bootstrap settings.'),

  'render region' => 'panels_bootstrap_layouts_style_region_render',
  'settings form' => 'panels_bootstrap_layouts_style_region_settings_form',
);

/**
 * Render region callback.
 *
 * @ingroup themeable
 */
function theme_panels_bootstrap_layouts_style_region_render($vars) {
  $display = $vars['display'];
  $panes = $vars['panes'];
  $settings = $vars['settings'];

  if ($panes) {
    $class = array('panel-panel', $vars['region_id']);

    if (!empty($settings['css_class'])) {
      $class[] = $settings['css_class'];
    }

    if ($settings['column_size']) {
      $class[] = 'span' . $settings['column_size'];
    }

    if ($settings['offset_size']) {
      $class[] = 'offset' . $settings['offset_size'];
    }

    $element = array(
      '#tag' => 'div',
      '#value' => implode('', $panes),
      '#attributes' => array('class' => $class)
    );

    if (!empty($settings['css_id'])) {
      $element['#attributes']['id'] = $settings['css_id'];
    }

    return theme('html_tag', array('element' => $element));
  }
}

/**
 * Region settings form callback.
 */
function panels_bootstrap_layouts_style_region_settings_form($style_settings, $display, $pid, $type, $form_state) {
  $form = array();

  $form['css_id'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS ID'),
    '#default_value' => isset($style_settings['css_id']) ? $style_settings['css_id'] : '',
    '#description' => t('CSS ID to apply to this pane. This may be blank.'),
  );

  $form['css_class'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS class'),
    '#default_value' => isset($style_settings['css_class']) ? $style_settings['css_class'] : '',
    '#description' => t('CSS class to apply to this pane. This may be blank.'),
  );

  $options = range(0, 12);
  $options[0] = t('-- None --');

  $form['column_size'] = array(
    '#type' => 'select',
    '#title' => t('Column size'),
    '#options' => $options,
    '#default_value' => isset($style_settings['column_size'])
      ? $style_settings['column_size']
      : 1,
  );

  $form['offset_size'] = array(
    '#type' => 'select',
    '#title' => t('Offset size'),
    '#options' => $options,
    '#default_value' => isset($style_settings['offset_size']) ? $style_settings['offset_size'] : 0,
  );

  return $form;
}

